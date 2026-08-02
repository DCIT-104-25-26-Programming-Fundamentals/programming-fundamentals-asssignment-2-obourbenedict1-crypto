// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

bool modulus(int a, int b, int& result) {
    if (b == 0) {
        return false;
    }
    result = a % b;
    return true;
}

double exponent(double base, int exp) {
    double result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void showMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Please enter a number between 1 and 7." << endl;
            continue;
        }

        cout << fixed << setprecision(2);

        if (choice == 5) {
            int a, b;
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            int result;
            if (modulus(a, b, result)) {
                cout << "Result: " << a << " % " << b << " = " << result << endl;
            } else {
                cout << "Error: Cannot perform modulus by zero." << endl;
            }

        } else if (choice == 6) {
            double base;
            int exp;
            cout << "Enter base    : ";
            cin >> base;
            cout << "Enter exponent: ";
            cin >> exp;

            double result = exponent(base, exp);
            cout << "Result: " << base << " ^ " << exp << " = " << result << endl;

        } else {
            double a, b;
            cout << "Enter first number : ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            if (choice == 1) {
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
            } else if (choice == 2) {
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
            } else if (choice == 3) {
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
            } else if (choice == 4) {
                double result;
                if (divide(a, b, result)) {
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
            }
        }

    } while (choice != 7);

    return 0;
}
