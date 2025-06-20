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
    std::string search_name;
    std::cout << "please type a name and i will return its corresponding score:\n";
    while (std::cin >> search_name) {
        int found_score = find_score(names, scores, search_name);
        if (found_score != -1) {
            std::cout << "the name " << search_name << " has the score of " << found_score << '\n';
        } else {
            std::cerr << "can't find name " << search_name << '\n';
        }
    }
}
