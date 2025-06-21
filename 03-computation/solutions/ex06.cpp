#include <iostream>
#include <string>
#include <vector>

int main() {
    const std::vector<std::string> valid_numbers = {
        "zero", "one", "two",   "three", "four",
        "five", "six", "seven", "eight", "nine",
    };
    for (std::string input; std::cin >> input;) {
        std::string output;
        // if input is a single digit, return the element of valid_values that
        // this digit is the index of
        if (input.size() == 1 && input[0] <= '9' && input[0] >= '0') {
            output = valid_numbers[input[0] - '0'];
        }
        // try to process a string
        for (int i = 0; i < valid_numbers.size(); i++) {
            if (input == valid_numbers[i]) {
                output = std::to_string(i); // to_string turns e.g. 3 to "3", 2.7 to "2.7"
            }
        }
        std::cout << output << '\n';
    }
}
