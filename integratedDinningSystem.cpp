#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem {
private:
    string name;
    double price;
    string category;

public:
    MenuItem(string n, double p, string c) {
        name = n;
        price = p;
        category = c;
    }

    string getName() { return name; }
    double getPrice() { return price; }
    string getCategory() { return category; }

    void display() {
        cout << name << " (" << category << ") - ₹" << price << endl;
    }
};

class Menu {
private:
    vector<MenuItem> items;

public:
    void addItem(MenuItem item) {
        items.push_back(item);
    }

    void showMenu() {
        cout << "\n---- MENU ----" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". ";
            items[i].display();
        }
    }

    MenuItem* getItem(int index) {
        if (index >= 0 && index < items.size())
            return &items[index];
        return nullptr;
    }
};

class Order {
private:
    string customerName;
    vector<MenuItem> orderItems;

public:
    Order(string name) {
        customerName = name;
    }

    void addItem(MenuItem item) {
        orderItems.push_back(item);
    }

    void showOrder() {
        cout << "\nOrder for " << customerName << ":\n";
        double total = 0;
        for (auto &item : orderItems) {
            cout << "- " << item.getName() << " : ₹" << item.getPrice() << endl;
            total += item.getPrice();
        }
        cout << "Total Bill: ₹" << total << endl;
    }
};

class Restaurant {
private:
    string name;
    Menu menu;
    vector<Order> orders;

public:
    Restaurant(string n) {
        name = n;
    }

    Menu& getMenu() { return menu; }

    void takeOrder(string customerName) {
        Order order(customerName);

        while (true) {
            menu.showMenu();
            cout << "\nEnter item number to add (0 to finish): ";
            int choice;
            cin >> choice;

            if (choice == 0) break;

            MenuItem* item = menu.getItem(choice - 1);
            if (item) {
                order.addItem(*item);
                cout << item->getName() << " added to your order!" << endl;
            } else {
                cout << "Invalid choice, try again." << endl;
            }
        }

        order.showOrder();
        orders.push_back(order);
    }
};

// ------------ MAIN PROGRAM ------------

int main() {
    Restaurant resto("Isha's Resto");

    // Add some items to the menu
    resto.getMenu().addItem(MenuItem("Pizza", 250, "Main Course"));
    resto.getMenu().addItem(MenuItem("Burger", 150, "Snacks"));
    resto.getMenu().addItem(MenuItem("Pasta", 200, "Main Course"));
    resto.getMenu().addItem(MenuItem("Cold Coffee", 100, "Beverage"));
    resto.getMenu().addItem(MenuItem("Brownie", 120, "Dessert"));

    cout << "Welcome to " << "Isha's Resto!" << endl;

    while (true) {
        string name;
        cout << "\nEnter your name: ";
        cin >> name;

        resto.takeOrder(name);

        cout << "\nTake another order? (y/n): ";
        char again;
        cin >> again;
        if (again == 'n' || again == 'N') break;
    }

    cout << "\nAll Orders Completed. Thank you!" << endl;
    return 0;
}
