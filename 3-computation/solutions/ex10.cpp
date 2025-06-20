#include <vector>
#include <iostream>

std::vector<int> gen_primes(int n) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; ++i) {
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    std::vector<int> primes;
    for (int i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i] == true) primes.push_back(i);
    }
    return primes;
}

int main() {
    int n = 0;
    std::cout << "> ";
    std::cin >> n;
    std::vector<int> primes = gen_primes(n); // generate primes up to 300
    for (int i = 0; i < primes.size(); ++i) {
        std::cout << primes[i] << (i + 1 == primes.size() ? "\n" : ", ");
    }
}
