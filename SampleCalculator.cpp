#include <iostream>
using namespace std;

class Calculator {
public:
    void showMenu() {         //Displays the menu with options for different operations
        cout << "Simple Calculator" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;

        
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;
    }

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return 0;
        }
        return a / b;
    }

    void run() {
        int choice;
        double num1, num2, result;

        do {
            showMenu();         //Displays the menu with options for different operations         
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            if (choice >= 1 && choice <= 4) {
                cout << "Enter the first number: ";
                cin >> num1;
                cout << "Enter the second number: ";
                cin >> num2;

                switch (choice) {
                    case 1:
                        result = add(num1, num2);
                        cout << "Result: " << result << endl;
                        break;
                    case 2:
                        result = subtract(num1, num2);
                        cout << "Result: " << result << endl;
                        break;
                    case 3:
                        result = multiply(num1, num2);
                        cout << "Result: " << result << endl;
                        break;
                    case 4:
                        result = divide(num1, num2);
                        if (num2 != 0) {
                            cout << "Result: " << result << endl;
                        }
                        break;
                }
            } else if (choice == 5) {
                cout << "Exiting the calculator. Goodbye!" << endl;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << endl;
        } while (choice != 5);
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}
