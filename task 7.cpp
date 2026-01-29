 #include <iostream>
using namespace std;

int main() {
    int choice;
    float quantity, total = 0;
    char again;

    do {
        cout << "===== RESTAURANT MENU =====\n";
        cout << "1. Chicken Karahi (Rs.1200 per KG)\n";
        cout << "2. Beef Karahi (Rs.1500 per KG)\n";
        cout << "3. Biryani (Rs.250 per plate)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter KG: ";
            cin >> quantity;
            total += quantity * 1200;
        }
        else if (choice == 2) {
            cout << "Enter KG: ";
            cin >> quantity;
            total += quantity * 1500;
        }
        else if (choice == 3) {
            cout << "Enter plates: ";
            cin >> quantity;
            total += quantity * 250;
        }
        else {
            cout << "Invalid Choice!\n";
        }

        cout << "Do you want to order more? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nTotal Bill = Rs." << total;
    cout << "\nThank you for visiting!";
    
    return 0;
}
