#include <iostream>     
#include <string>
#include <ctime>            
#include <cstdlib>      
#include <vector>        
using namespace std;

int main() {
    srand(time(0));

    cout << "Welcome to Fav games!\n";
    
    cout << "What would you like to play?\n";
    cout << "Press 1 to play list name\n";
    cout << "Press 2 to get in the adventuring loop!\n";

    int numInput = -1;
    cin >> numInput;

    if(numInput == 1) 
    {
        cout << "List Fav game\n";
        
        string response = "";

        cout << "This is the list game\n";

        cout << "You can ADD, QUIT the game and SHOW the names add it to the list\n";

        cout << "I will start adding and removing some names from the list but you can add 8 more names to the list\n";

        string names[10];
        names[0] = "(Patricio)";        
        names[1] = "Patricio";        
        names[2] = "Brian";

        cout << "My name is " << names[1] << ".\n";

        cout << "My teacher is " << names[2] << ".\n";

        cout << "I will take Brian out because He is grading this game";

          vector<string> list;

        cout << "There are " << list.size() << " names in my list.\n";

        list.push_back("Patricio");
        list.push_back("Brian");

        cout << "The first name in my list is a " << list[0] << ".\n";

        cout << "List:\n";

        for(int i = 0; i < list.size(); i++) {
            cout << list[i] << "\n";
        }

        cout << "We don't need a Brian, I will change it for my brother Lucas.\n";
        list[1] = "Lucas";

        for(int i = 0; i < 10; i += 1) {
            if(names[i] == "") continue;        
            cout << names[i] << "\n";
        }

        cout << "And those are all the changes I will do.\n";


        string favGames[10];
        int index = 0;           

        while (true) {

            string input = "";
            cout << "What would you like to do?\n";
            cin >> input;


            if(input == "add") {
                if(index >= 10) {
                    cout << "The list is full!\n";

                }
                else {

                    cout << "What name would you like to add?\n";
                    cin >> input;
                    favGames[index] = input;
                    index += 1;        

                }
            }
            else if(input == "show") {

                for(int i = 0; i < 10; i += 1) {
                    if(favGames[i] == "") continue;
                    cout << i + 1 << ". " << favGames[i] << "\n";
                }
            }
            else if (input == "quit") {

                cout << "Thanks for playing!\n";
                break;
            }

        }


    }
    if(numInput == 2)
    {
        string response = "";
        
        do {
            cout << "Let's go to the adventure!\n";
            cout << "Do you want to keep adventuring in the loop?\n";
            cin >> response;

        } while(response != "no");

        while(true) {
            string response;
            cout << " Yeah! It is been fun\n";
            cout << "Shoul we keep going?\n";
            cin >> response;

            if(response == "no") {
                cout << "Alright! Let's go home.\n";
                break;
            }
        }

        cout << "You exit the infinity loop. Congrat!.\n";
    }
    
}
