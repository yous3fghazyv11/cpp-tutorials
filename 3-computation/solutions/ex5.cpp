#include <iostream>
#include <limits>
#include <string>

int main() {
    int low = -1;
    int high = 101;
    std::cout << "Think of a number from 0 to 100 and i will guess it:\n";
    for (char ans; abs(low - high) > 1;) {
        std::cout << "Is it " << (low + high) / 2 << "? (h = higher, l = lower, y = yes): ";
        std::string input;
        std::cin >> input;
        if (std::cin.eof()) return 0;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (input.size() > 1) {
            std::cerr << "invalid input\n";    
            continue;
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
