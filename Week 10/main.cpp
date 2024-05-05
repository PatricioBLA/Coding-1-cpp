// Brian Foster Week 11 Wednesday Coding 1a
// let's talk abotu structs later, we should've done that earlier.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// an enumerator is a custom variable that evaluates to an integer.
enum itemType {
    // equal to 0, 1, and 2, respectively.
    weapon, tool, consumable
};

enum elementalType {
    basic = 0, fire = 1, ice = 2, candy = 3, slime = 4
};

class item {
public:
    itemType type = weapon;
    int damage = 0;
    string name = "";
    elementalType element = basic;
    int remainingUses = 0;
    int healingAmount = 0;

    // build a fancy constructor
    item (string n, itemType t) {
        name = n;        // assign the name of the item to the given name.
        type = t;

        if(type == weapon) {
            // calculate damage and element
            damage = rand() % 5 + 3;
            element = (elementalType)(rand() % 4);    // typecast an int into an elementalType.
            remainingUses = 9999;
            healingAmount = 0;
        }
        else if(type == tool) {
            damage = 1;
            element = basic;
            remainingUses = rand() % 5 + 1;
            healingAmount = 0;
        }
        else if(type == consumable) {
            healingAmount = rand() % 5 + 1;
            damage = -healingAmount;
            element = basic;
            remainingUses = 1;
        }
    } // end of item constructor

    void Inspect() {
        cout << name << " has damage of " << damage << ", it's element is " << elementToString(element) << "\n";
        cout << "It can be used " << remainingUses << " more times, heals for " << healingAmount << ",\n";
        cout << "And is of the item type " << typeToString(type) << ".\n\n";
    }

    string typeToString(itemType type) {
        // this is a switch statement. It's like an if statement, but it 
            // only has to test once! All of the possible values are mapped.
        switch(type) {
            case weapon: 
                return "weapon"; 
                break;
            case tool: 
                return "tool"; 
                break;
            case consumable: 
                return "consumable";
                break;
            default: 
                return "unknown";
                break;
        }
    }

    string elementToString(elementalType element) {
        switch(element) {
            case basic: return "basic"; break;
            case fire: return "fire"; break;
            case ice: return "ice"; break;
            case candy: return "candy"; break;
            case slime: return "slime"; break;
            default: return "unknown";
        }
    }
};


// create a class named enemy based on the Adventure assignment over spring break.
class enemy {
public:
    item heldItem;
};


int main() {
    srand(time(0));
    cout << "More Classes!\n";

    // a vector of weapon names
    vector<string> weaponNames = {
        "Excalibur",
        "Mjolnir",
        "Sting",
        "Blade of Chaos",
        "Master Sword",
        "Deathbringer",
        "Soul Edge",
        "Doombringer",
        "Frostmourne",
        "Dragonslayer"
    };

    random_shuffle(weaponNames.begin(), weaponNames.end());   // #include <algorithm>

    item sting("Sting", weapon);
    sting.Inspect();

    vector<item> weapons;

    for(int i = 0; i < weaponNames.size(); i++) {
        weapons.push_back(item(weaponNames[i], weapon));    // create a weapon.
        weapons[i].Inspect();        // display the newly created weapon.
    }
}

/* RECAP
    enumerators are a custom variable type with a limited number of possible values
    switch statements map all possible outcomes to a single test.
    classes can have other classes inside of them (enemy can hold an item)
    typecasting is when we want the compiler to try to change a variable into another variable.
    AI is great for generating a vector of names.
*/

/* HOMEWORK
    create BASIC adventure functionality using the enemy class for each encounter.
    each enemy must use a weapon.
    each enemy has health.
    player has option of using weapon or consumable
    at least one encounter, to the death.

    i am grading based on the enemy class, does it have the functionality that it needs
    to interact with the player
*/
