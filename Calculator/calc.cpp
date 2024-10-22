#include <iostream>
#include <stdexcept>

void showMenu() {
    std::cout << "Simple Calculator\n";
    std::cout << "=================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
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
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting...\n";
            break;
        }

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        try {
            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 2:
                    result = subtract(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 3:
                    result = multiply(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 4:
                    result = divide(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}