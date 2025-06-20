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

std::vector<std::string> find_name(std::vector<std::string> names, std::vector<int> scores, int score) {
    std::vector<std::string> found_names;
    for (int i = 0; i < names.size(); i++) {
        if (scores[i] == score) found_names.push_back(names[i]);
    }
    return found_names;
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

    int search_score;
    std::vector<std::string> found_names;
    std::cout << "please type a name and i will return its corresponding score:\n";
    while (std::cin >> search_score) {
        found_names = find_name(names, scores, search_score);
        if (found_names.size() < 1) {
            std::cout << "No names for that score\n";
            continue;
        }
        std::cout << "Names with score of " << search_score << ": ";
        for (int i = 0; i < found_names.size(); ++i) {
            std::cout << found_names[i] << (i + 1 == found_names.size() ? "\n" : ", ");
        }
    }
}
