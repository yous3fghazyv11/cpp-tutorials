#include <vector>
#include <iostream>

bool end_of_input(std::string name, int score) {
    if (name == "NoName" && score == 0) {
        return true;
    }
    return false;
}

bool duplicate(std::vector<std::string> names, std::string name) {
    for (std::string n : names) {
        if (n == name) {
            return true;
        }
    }
    return false;
}

int find_score(std::vector<std::string> names, std::vector<int> scores, std::string name) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) return scores[i];
    }
    return -1;
}

int main() {
    std::string name;
    int score = 0;
    std::vector<std::string> names;
    std::vector<int> scores;

    std::cout << "please enter names and scores (\"NoName 0\" to stop):\n";
    while (std::cin >> name >> score) {
        if (end_of_input(name, score)) {
            break;
        }
        if (duplicate(names, name)) {
            std::cerr << "Name can't be entered twice\n";
            return 0;
        }
        names.push_back(name);
        scores.push_back(score);
    }

    if (names.size() < 1) {
        std::cerr << "no input collected\n";
        return 0;
    }

    std::cout << "here's a list of names and scores you entered:\n";
    for (int i = 0; i < names.size(); i++) {
        std::cout << names[i] << '\t' << scores[i] << '\n';
    }
}
