#include <iostream>

using namespace std;

// Function to read two double type numbers from the keyboard
void read(double& num1, double& num2) {
    cout << "Enter the first number: ";
    while (!(cin >> num1)) {
        cin.clear();
        cout << "Invalid input. Please enter a valid number: ";
        while (cin.get() != '\n') {
            // Clear characters until a newline character is encountered
        }
    }

    cout << "Enter the second number: ";
    while (!(cin >> num2)) {
        cin.clear();
        cout << "Invalid input. Please enter a valid number: ";
        while (cin.get() != '\n') {
            // Clear characters until a newline character is encountered
        }
    }
}

// Function to calculate the division of two numbers
double divide(double num1, double num2) {
    if (num2 == 0) {
        throw "Error: Division by zero is not allowed.";
    }
    return num1 / num2;
}

int main() {
    double number1, number2;

    try {
        read(number1, number2);

        try {
            double result = divide(number1, number2);
            cout << "Result of division: " << result << endl;

        } catch (const char* e) {
            cerr << "Runtime Error: " << e << endl;
        }

    } catch (const char* e) {
        cerr << "Invalid Argument: " << e << endl;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
    }

    return 0;
}
