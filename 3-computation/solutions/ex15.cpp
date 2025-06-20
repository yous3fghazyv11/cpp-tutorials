#include <vector>
#include <iostream>

int get_mode(std::vector<int> v) {
    int mode = -1;
    int biggest = 0;
    for (int i = 0; i < v.size(); i++) {
        int count = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[i] == v[j]) {
                ++count;
            }
        }
        if (count > biggest) {
            mode = v[i];
            biggest = count;
        }
    }
    return mode;
}

int main() {
    int mode = get_mode({1, 2, 3, 4, 5, 1, 2, 2, 2, 3, 4, 5, 5}); // should be 2
    std::cout << mode << '\n';
}
