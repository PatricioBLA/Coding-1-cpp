// Brian Foster Week 7 Day 1 Coding 1 in the morning.
// Functions!!!!

// declaring and defining a function
// calling a function
// return types and returning values
// input parameters

// functions are reuseable blocks of code that can be called in another function.


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// global variables exist in all functions, in all code blocks.
// vector<string> hateFoods = {"One", "two", "three", "four", "five" };

// declaring and defining our function
void SayHello() {
    cout << "Hello!\n";
}

// declaring and defining a new function named "ShowVector()"
// thr return type is void, which means it just runs, it doesn't return anything.
// it has one input parameter, a vector of strings named vec. we are passing by copy
void ShowVector(vector<string> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ".\n";
    }
}


// declaring and defining a new function named "castdamage"
// it has two input parameters, min and max, which are both integers.
// it's return type is int, which means it will send back an integer.
int CastDamage(int min, int max) {        // pretend that min = 5 and max = 10
    // roll for damage.
    int damage = (rand() % (max - min)) + min;

    // crit check, if rand() is 5, double damage.
    int critRoll = rand() % 5;
    if(critRoll == 4) {
        // double the damage.
        damage += damage;
        cout << "CRITICAL HIT!";
    }

    return damage;
}

// create a function that returns a string. (dead or alive)
// it needs no input parameters
// it will ask the player how much health they have, 
// assign that to a variable named "int health"
// and then call castDamage() with the min being 5 and the max being health.
// subtract castDamage() from health.
// if health is less than or equal to 0, return "dead"
// else, return "alive".

// return type, FunctionName, (input parameters) {
string BossFight() {
    cout << "How much health do you have?\n";
    int health;
    cin >> health;

    health -= CastDamage(5, health);

    if(health > 0) {
        return "alive";
    }
    else {
        return "dead";
    }
}



int main() {
    srand(time(0));
    SayHello();        // calling our function
    string playerState = BossFight();
    cout << "The player is " << playerState << ".\n";

    for(int i = 0; i < 10; i++) {
        cout << "The enemy has done " << CastDamage(5, 10) << " damage!!\n";
    }

    // create a vector of least-fav foods
        // use a collection initializer
    // use a for loop to display them    

    vector<string> unlikeableFoods = {"One", "two", "three", "four", "five" };

    ShowVector(unlikeableFoods);

    cout << "Right, so those are the foods that I hate. OH, I forgot, I also hate mashed potates.\n";
    unlikeableFoods.push_back("Mashed Pototes");

    ShowVector(unlikeableFoods);

    cout << "I don't care for dirt.... it doesn't taste very good.\n";
    unlikeableFoods.push_back("dirt");

    ShowVector(unlikeableFoods);    // calling a function and sending one input parameter.



}


// please declare and define in the same place.
// void ShowVector(vec) {
//     for(int i = 0; i < hateFoods.size(); i++) {
//         cout << hateFoods[i] << ".\n";
//     }
// }
