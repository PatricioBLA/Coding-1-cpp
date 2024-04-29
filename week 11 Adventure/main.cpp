#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Weapon {
public:
    Weapon(const std::string& name, int damage) : name(name), damage(damage) {}

    int getDamage() const {
        return damage;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    int damage;
};

class Enemy {
public:
    Enemy(const std::string& name, int health, const Weapon& weapon) : name(name), health(health), weapon(weapon) {}

    int getHealth() const {
        return health;
    }

    const std::string& getName() const {
        return name;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    const Weapon& getWeapon() const {
        return weapon;
    }

private:
    std::string name;
    int health;
    Weapon weapon;
};

class Player {
public:
    Player(int health) : health(health) {}

    int getHealth() const {
        return health;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useWeapon(Weapon& weapon, Enemy& enemy) {
        int damage = weapon.getDamage();
        enemy.takeDamage(damage);
        std::cout << "You attack " << enemy.getName() << " with " << weapon.getName() << " causing " << damage << " damage.\n";
    }

    void useConsumable() {
        // Implement consumable functionality
        std::cout << "You use a consumable.\n";
    }

private:
    int health;
};

int main() {
    srand(time(0));

    Weapon sword("Sword", 10);
    Weapon axe("Axe", 12);

    Enemy enemy1("Goblin", 20, sword);
    Enemy enemy2("Orc", 25, axe);

    Player player(100);

    while (enemy1.getHealth() > 0 || enemy2.getHealth() > 0) {
        int choice = rand() % 2; // Randomly choose between using weapon or consumable
        if (choice == 0) {
            if (enemy1.getHealth() > 0) {
                player.useWeapon(sword, enemy1);
                if (enemy1.getHealth() <= 0) {
                    std::cout << enemy1.getName() << " has been defeated!\n";
                }
            } else {
                std::cout << enemy1.getName() << " has already been defeated!\n";
            }
        } else {
            player.useConsumable();
        }

        if (choice == 1) {
            if (enemy2.getHealth() > 0) {
                player.useWeapon(axe, enemy2);
                if (enemy2.getHealth() <= 0) {
                    std::cout << enemy2.getName() << " has been defeated!\n";
                }
            } else {
                std::cout << enemy2.getName() << " has already been defeated!\n";
            }
        } else {
            player.useConsumable();
        }

        if (player.getHealth() <= 0) {
            std::cout << "You have been defeated!\n";
            break;
        }
    }

    if (enemy1.getHealth() <= 0 && enemy2.getHealth() <= 0) {
        std::cout << "Congratulations! You have defeated all enemies!\n";
    }

    return 0;
}
