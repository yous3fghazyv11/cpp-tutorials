#include <vector>
#include <iostream>

int main() {
    constexpr int MAX = 100;
    std::vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; ++i) {
        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = 0; i < is_prime.size(); i++) {
        if (is_prime[i] == true) std::cout << i << ' ';
    }
    std::cout << '\n';
}
