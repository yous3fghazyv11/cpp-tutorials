#include <iostream>

int main() {
    double current_rice = 1;
    double required_rice = 0;
    std::cout << "how much rice do you want?:\n> ";
    std::cin >> required_rice;
    for(int i = 1; i <= 64; i++) { // i is the block number
        if (i != 1) current_rice *= 2;;
        if (current_rice >= required_rice) {
            std::cout << "you will need to fill in up to " << i << " blocks\n";
            break;
        }
    } 
}
