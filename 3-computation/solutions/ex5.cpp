#include <cstdlib>
#include <iostream>

int main() {
    int low = -1;
    int high = 101;
    std::cout << "Think of a number from 0 to 100 and i will guess it:\n";
    for (char ans ='\0'; std::cin >> ans;) {// control variable is where the input is going to be stored
        if (abs(high - low) <= 1) {
            std::cout << "did you forget your number?\n";
            return 0;
        }
        std::cout << "Is it " << (low + high) / 2 << "? (h = higher, l = lower, y = yes): "; // prompt
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
    
    return 0;
}
