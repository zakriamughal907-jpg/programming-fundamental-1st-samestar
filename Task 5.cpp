#include <iostream>
using namespace std;

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int main() {
    int choice;
    float num1, num2;
    char again;

    do {
        cout << "\n--- Calculator Menu ---\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        }

        switch (choice) {
            case 1:
                cout << "Result = " << add(num1, num2);
                break;
            case 2:
                cout << "Result = " << subtract(num1, num2);
                break;
            case 3:
                cout << "Result = " << multiply(num1, num2);
                break;
            case 4:
                cout << "Result = " << divide(num1, num2);
                break;
            case 5:
                cout << "Exiting program...";
                return 0;
            default:
                cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}