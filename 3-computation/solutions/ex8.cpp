
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> valid_numbers = {
    "zero", "one", "two",   "three", "four",
    "five", "six", "seven", "eight", "nine",
};

std::string convert(std::string input) {
    std::string output;
    // if input is a single digit, return that digit
    if (input.size() == 1 && input[0] <= '9' && input[0] >= '0') {
        output = input[0];
    }
    // try to process a string
    for (int i = 0; i < valid_numbers.size(); i++) {
        if (input == valid_numbers[i]) {
            output = std::to_string(i); // to_string turns e.g. 3 to "3", 2.7 to "2.7"
        }
    }
    return output;
}

int main() {
    while (std::cout << "> ") {
        std::string num1, num2;
        char op = '\0';
        std::cin >> num1 >> op >> num2;
        int left = convert(num1)[0] - '0';
        int right = convert(num2)[0] - '0';
        int result = 0;
        switch (op) {
            case '+': result =  left + right; break;
            case '-': result =  left - right; break;
            case '*': result =  left * right; break;
            case '/':
                if (right != 0) result = left / right;
                else std::cerr << "error: divion by zero\n";
                continue;
            default:
                std::cerr << "inalid operator\n";
                continue;
        }
        std::cout << "Result: " << result << '\n';
    }
}
