#include <iostream>
#include <limits>
#include <string>

// ============================================================================
// Function Declarations (Prototypes)
// ============================================================================
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void displayWelcomeMessage();
void displayMenu();
double getValidNumber(const std::string& prompt);
void clearInputBuffer();

// ============================================================================
// Main Function
// ============================================================================
int main() {
    // 1. Display welcome message
    displayWelcomeMessage();

    char continueChoice = 'y';

    // Loop to allow repeated calculations
    do {
        // 2. Display menu of four operations
        displayMenu();

        // 3. Ask the user to select an operation
        char operation;
        std::cout << "Enter your choice (1-4 or +, -, *, /): ";
        if (!(std::cin >> operation)) {
            // EOF or input closed
            break;
        }
        clearInputBuffer();

        // 7. Handle invalid menu selections using if-else statements (switch-free)
        if (operation == '1' || operation == '+' ||
            operation == '2' || operation == '-' ||
            operation == '3' || operation == '*' ||
            operation == '4' || operation == '/') {

            // 4. Accept two numbers with input validation
            double num1 = getValidNumber("Enter the first number:  ");
            double num2 = getValidNumber("Enter the second number: ");

            // 5 & 6. Perform calculation using functions and display the result clearly
            // Implemented using if-else statements (switch-free)
            if (operation == '1' || operation == '+') {
                double result = add(num1, num2);
                std::cout << "\n>>> Result: " << num1 << " + " << num2 << " = " << result << "\n";
            }
            else if (operation == '2' || operation == '-') {
                double result = subtract(num1, num2);
                std::cout << "\n>>> Result: " << num1 << " - " << num2 << " = " << result << "\n";
            }
            else if (operation == '3' || operation == '*') {
                double result = multiply(num1, num2);
                std::cout << "\n>>> Result: " << num1 << " * " << num2 << " = " << result << "\n";
            }
            else if (operation == '4' || operation == '/') {
                // 8. Prevent division by zero
                if (num2 == 0.0) {
                    std::cout << "\n[Error] Cannot divide by zero! Division by zero is undefined in mathematics.\n";
                } else {
                    double result = divide(num1, num2);
                    std::cout << "\n>>> Result: " << num1 << " / " << num2 << " = " << result << "\n";
                }
            }
        }
        else {
            // Invalid menu choice feedback
            std::cout << "\n[Error] Invalid operation selected! Please choose 1, 2, 3, 4 or +, -, *, /.\n";
        }

        // 9. Ask whether the user wants another calculation
        std::cout << "\nWould you like to perform another calculation? (y/n): ";
        continueChoice = 'n';
        if (!(std::cin >> continueChoice)) {
            break;
        }
        clearInputBuffer();

        // Validate continuation choice (must be 'y', 'Y', 'n', or 'N')
        while (continueChoice != 'y' && continueChoice != 'Y' &&
               continueChoice != 'n' && continueChoice != 'N') {
            std::cout << "Invalid input. Please enter 'y' to continue or 'n' to quit: ";
            if (!(std::cin >> continueChoice)) {
                continueChoice = 'n';
                break;
            }
            clearInputBuffer();
        }

        std::cout << "\n";

    } while (continueChoice == 'y' || continueChoice == 'Y');

    // 10. Exit gracefully when the user chooses to quit
    std::cout << "========================================================\n";
    std::cout << "  Thank you for using Basic Calculator! Have a great day!\n";
    std::cout << "========================================================\n";

    return 0;
}

// ============================================================================
// Arithmetic Operation Functions
// ============================================================================

/**
 * Adds two double numbers.
 * @param a First number
 * @param b Second number
 * @return Sum of a and b
 */
double add(double a, double b) {
    return a + b;
}

/**
 * Subtracts the second number from the first number.
 * @param a First number
 * @param b Second number
 * @return Difference between a and b (a - b)
 */
double subtract(double a, double b) {
    return a - b;
}

/**
 * Multiplies two double numbers.
 * @param a First number
 * @param b Second number
 * @return Product of a and b
 */
double multiply(double a, double b) {
    return a * b;
}

/**
 * Divides the first number by the second number.
 * Precondition: b must not be zero (verified by caller before invocation).
 * @param a Numerator
 * @param b Denominator
 * @return Quotient of a / b
 */
double divide(double a, double b) {
    return a / b;
}

// ============================================================================
// Helper & UI Functions
// ============================================================================

/**
 * Displays the welcome banner.
 */
void displayWelcomeMessage() {
    std::cout << "========================================================\n";
    std::cout << "               BASIC CALCULATOR (C++)                   \n";
    std::cout << "========================================================\n";
    std::cout << "Welcome to the beginner-friendly C++ console calculator!\n";
    std::cout << "Perform addition, subtraction, multiplication, and division.\n\n";
}

/**
 * Displays the menu of four supported mathematical operations.
 */
void displayMenu() {
    std::cout << "----------------- OPERATIONS MENU ----------------------\n";
    std::cout << "  1. Addition       (+)\n";
    std::cout << "  2. Subtraction    (-)\n";
    std::cout << "  3. Multiplication (*)\n";
    std::cout << "  4. Division       (/)\n";
    std::cout << "--------------------------------------------------------\n";
}

/**
 * Clears any remaining characters in standard input buffer up to newline.
 */
void clearInputBuffer() {
    if (std::cin.good()) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
 * Prompts user for a numeric value and validates the input.
 * Handles non-numeric characters and ensures stream validity.
 * @param prompt Text prompt shown to the user
 * @return Validated double value
 */
double getValidNumber(const std::string& prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        if (std::cin >> number) {
            clearInputBuffer();
            return number;
        } else {
            if (std::cin.eof()) {
                return 0.0;
            }
            std::cout << "  [!] Invalid numerical input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
