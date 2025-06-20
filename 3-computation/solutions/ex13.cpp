#include <vector>
#include <iostream>

int main() {
    std::vector<bool> is_prime(101, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 100; ++i) {
        for (int j = i * i; j <= 100; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = 0; i < is_prime.size(); i++) {
        if (is_prime[i] == true) std::cout << i << ' ';
    }
    std::cout << '\n';
}
