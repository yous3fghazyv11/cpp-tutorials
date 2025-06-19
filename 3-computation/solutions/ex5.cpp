#include <iostream>
#include <string>

int main() {
    int low = -1;
    int high = 101;
    std::cout << "Think of a number from 0 to 100 and i will guess it:\n";
    for (char ans; abs(low - high) > 1;) {// control variable is where the input is going to be stored
        std::cout << "Is it " << (low + high) / 2 << "? (h = higher, l = lower, y = yes): "; // prompt
        // getting input in a string
        std::string input; 
        std::getline(std::cin, input);
        if (input.size() > 1) {  // making sure the user types exactly on character
            std::cerr << "invalid input\n";
            continue;
        }
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            return 0;
        }
        ans = input[0];
        switch (ans) {
        case 'y':
            std::cout << "yaaay\n";
            return 0;
        case 'h':
            low = (low + high) / 2;
            break;
        case 'l':
            high = (low + high) / 2;
            break;
        default:
            std::cerr << "invalid input\n";
            break;
        }
    }
    std::cout << "did you forget what number you guessed or something?\n";
    return 0;
}
