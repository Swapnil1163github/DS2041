#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
    string name;
    int qua;
    double price;
};

int main() {
    const int MAX_ITEMS = 100;
    Item inv[MAX_ITEMS];
    int numItems = 0;
    int choice;

    ifstream inFile("inventory_management.txt");
    if (inFile.is_open()) {
        string name;
        int qua;
        double price;
        while (inFile >> name >> qua >> price) {
            inv[numItems].name = name;
            inv[numItems].qua = qua;
            inv[numItems].price = price;
            numItems++;
        }
        inFile.close();
    }

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (numItems >= MAX_ITEMS) {
                    cout << "Inventory is full. Cannot add more items.\n";
                    break;
                }
                cout << "Enter item name: ";
                cin >> inv[numItems].name;
                cout << "Enter quantity: ";
                cin >> inv[numItems].qua;
                cout << "Enter price: ";
                cin >> inv[numItems].price;
                numItems++;
                cout << "Item added to inventory.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the item to remove: ";
                cin >> name;

                int found = -1;
                for (int i = 0; i < numItems; i++) {
                    if (inv[i].name == name) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    for (int i = found; i < numItems - 1; i++) {
                        inv[i] = inv[i + 1];
                    }
                    numItems--;
                    cout << "Item '" << name << "' removed from inventory.\n";
                } else {
                    cout << "Item '" << name << "' not found in inventory.\n";
                }
                break;
            }
            case 3: {
                cout << "Current Inventory:\n";
                cout << "Name\tQuantity\tPrice\n";
                cout << "----------------------------------------------\n";
                for (int i = 0; i < numItems; i++) {
                    cout << inv[i].name << "\t"
                         << inv[i].qua << "\t\t"
                         << inv[i].price << "\n";
                }
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    ofstream outFile("inventory_management.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < numItems; i++) {
            outFile << inv[i].name << " "
                    << inv[i].qua << " "
                    << inv[i].price << "\n";
        }
        outFile.close();
    } else {
        cout << "Unable to save inventory data to file.\n";
    }

    return 0;
}