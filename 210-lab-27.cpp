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

   int choice;
   string name;

   do {
   cout << "\nMenu:\n"; // Display menu
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch(choice) {
            case 1: { // Add villager
                string species, catchphrase;
                int level;
                cout << "Villager name: ";
                cin >> name;
                cout << "Friendship level: ";
                cin >> level;
                cin.ignore(); // ignore leftover newline
                cout << "Species: ";
                cin >> species;
                cin.ignore();
                cout << "Catchphrase: ";
                getline(cin, catchphrase);

                villagerData[name] = make_tuple(level, species, catchphrase);
                cout << name << " added.\n";
                printVillagers(villagerData);
                break;
            }

            case 2: { // Delete villager
                cout << "Enter villager name to delete: ";
                cin >> name;
                if(villagerData.erase(name))
                    cout << name << " deleted.\n";
                else
                    cout << name << " not found.\n";
                printVillagers(villagerData);
                break;
            }
            case 3: // Increasing friendship
                cout << "Enter villager name: ";
                cin >> name;
                 if (villagerData.find(name) != villagerData.end()) {
                    get<0>(villagerData[name]) += 1;
                    cout << name << "'s friendship increased.\n";
                } else {
                    cout << name << " not found.\n";
                }
                printVillagers(villagerData);
                break;
            case 4: // Decreasing friendship
                 cout << "Enter villager name: ";
                cin >> name;
                if (villagerData.find(name) != villagerData.end()) {
                    if (get<0>(villagerData[name]) > 0)
                        get<0>(villagerData[name]) -= 1;
                    cout << name << "'s friendship decreased.\n";
                } else {
                    cout << name << " not found.\n";
                }
                printVillagers(villagerData);
                break;
            case 5: // Searches for villager
                 cout << "Enter villager name: ";
                cin >> name;
                if (villagerData.find(name) != villagerData.end()) {
                    auto& v = villagerData[name];
                    cout << name << " [" 
                         << get<0>(v) << ", "
                         << get<1>(v) << ", "
                         << get<2>(v) << "]\n";
                } else {
                    cout << name << " not found.\n";
                }
                break;
            case 6: // Exits program
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 6);
        
          return 0;

        }
   
   
    