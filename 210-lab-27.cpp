// COMSC-210 | Lab 27 | Mamadou Sissoko
// IDE used: Visual Studio Code
// Villager map 

#include <iostream>
#include <map>
#include <tuple>
using namespace std;

void printVillagers(const map<string, tuple<int,string,string>>& villagerData) {
    cout << "\nVillager details:\n";
    for (const auto& pair : villagerData) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]" << endl;
    }
}
int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // inserts villager data as tuples
    villagerData["Audie"] = make_tuple(10, "Wolf", "Yippee!");
    villagerData["Raymond"] = make_tuple(8, "Cat", "Hello there!");
    villagerData.insert({"Marshal", make_tuple(7, "Squirrel", "Hey hey hey!")});

   int choice
   string name;

   do {
   cout << "\nMenu:\n"; // Display menu
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search for Villager\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch(choice) {
            case 1:
                cout << "Enter villager name: ";
                cin >> name;

            case 2:

            case 3:

            case 4:
   
        }
         } return 0;

        }
   
   
    