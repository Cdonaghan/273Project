#include "inventory.h"

vector<character> items;
    void addItem(character character) {
        items.push_back(character);
    }
    void removeItem(int index) {
        items.erase(items.begin() + index);
    }
    void display() {
        if (items.empty()) {
            cout << "Your inventory is empty.\n";
        } else {
            cout << "Your inventory:\n";
            for (int i = 0; i < items.size(); i++) {
                cout << i + 1 << ". " << items[i].name << " (" << items[i].value << ")\n";
            }
        }
    }