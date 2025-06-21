#include <cstdlib>
#include <iostream>

// this program can't be exited normally, you will have to forcefully kill it
// more on that in the next lecture

int main() {
    int low = -1;
    int high = 101;
    std::cout << "Think of a number from 0 to 100 and i will guess it:\n";
    while (true) {
        char ans = '\0';
        if (abs(high - low) <= 1) {
            std::cout << "did you forget your number?\n";
            return 0;
        }
        std::cout << "Is it " << (low + high) / 2 << "? (h = higher, l = lower, y = yes): "; 
        std::cin >> ans;
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
