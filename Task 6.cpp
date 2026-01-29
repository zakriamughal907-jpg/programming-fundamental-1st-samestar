#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n--- Restaurant Menu ---\n";
    cout << "1. Burger     Rs.250\n";
    cout << "2. Pizza      Rs.500\n";
    cout << "3. Fries      Rs.150\n";
    cout << "4. Sandwich   Rs.200\n";
    cout << "5. Juice      Rs.100\n";
    cout << "6. Exit\n";
}

float calculateItemCost(float price, int quantity) {
    return price * quantity;
}

float calculateFinalBill(float total) {
    float tax = total * 0.10;
    return total + tax;
}

int main() {
    int choice, quantity;
    float total = 0, price;
    char again;

    do {
        showMenu();
        cout << "Enter item number: ";
        cin >> choice;

        if (choice == 6)
            break;

        cout << "Enter quantity: ";
        cin >> quantity;

        switch (choice) {
            case 1: price = 250; break;
            case 2: price = 500; break;
            case 3: price = 150; break;
            case 4: price = 200; break;
            case 5: price = 100; break;
            default:
                cout << "Invalid choice!";
                continue;
        }

        total = total + calculateItemCost(price, quantity);

        cout << "Order more items? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    float finalBill = calculateFinalBill(total);

    cout << "\nTotal Bill (including 10% tax): Rs." << finalBill << endl;

    return 0;
}