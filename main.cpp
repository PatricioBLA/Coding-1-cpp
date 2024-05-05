#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

string askYesNo(string question) {
    string answer;
    do {
        cout << question << " (yes/no): ";
        cin >> answer;
    } while (answer != "yes" && answer != "no");
    return answer;
}

int main() {
    srand(time(0)); // Seed set for random number

    int health = 10;
    int gold = 0;
    int turns = 0;

    do {
        turns++;
        cout << "Turn " << turns << ":" << endl;
        string decision = askYesNo("Would you like to go adventuring?");
        if (decision == "yes") {
            int attack = RollDie();
            int block = RollDie();
            cout << "You encountered an orc!" << endl;
            cout << "Attack Roll: " << attack << endl;
            cout << "Block Roll: " << block << endl;

            if (block >= attack) {
                cout << "You successfully blocked the orc's attack!" << endl;
                health--;
                cout << "You lost 1 health point. Health remaining: " << health << endl;
                int foundGold = RollDie(10); // Random amount of gold between 1 to 10
                cout << "You found " << foundGold << " gold!" << endl;
                gold += foundGold;
            } else {
                cout << "You failed to block the orc's attack!" << endl;
                health -= attack;
                if (health <= 0)
                    break; // Player dies
            }
        } else {
            break; // Player decides to stop adventuring
        }
    } while (health > 0);

    if (health > 0) {
        cout << "You survived for " << turns << " turns." << endl;
        cout << "You found " << gold << " gold." << endl;
        if (health < 5)
            cout << "Your health is low. Consider visiting a doctor." << endl;
    } else {
        cout << "You have died. You had " << gold << " gold left by your body." << endl;
    }

    return 0;
}
