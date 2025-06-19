#include <iostream>
#include <limits>

int main() {
    std::cout << "enter two numbers and operator in this format: (n op n)\n";
    for (double result; std::cout << "> ";) {
        char op = ' ';
        double num1 = 0, num2 = 0;
        std::cin >> num1 >> op >> num2;
        if (std::cin.fail()) {
            if (std::cin.eof()) return 0;
            std::cout << "bad input\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (op) {
            case '+': result =  num1 + num2; break;
            case '-': result =  num1 - num2; break;
            case '*': result =  num1 * num2; break;
            case '/':
                if (num2 != 0) result = num1 / num2;
                else std::cerr << "error: divion by zero\n";
                continue;
            default:
                std::cerr << "inalid operator\n";
                continue;
        }
        std::cout << "Result: " << result << '\n';
    }
}
