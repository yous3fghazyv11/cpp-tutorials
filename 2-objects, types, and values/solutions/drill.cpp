#include <iostream>

int main() {
    std::cout << "Write the name of the person you want to write to:\n> ";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Dear " << first_name << ", \n";
    std::cout << "\tHow are you? I'm fine. I miss you.\n";
    std::cout << "what are you up to? I've been working on a programming course!\n";
    // \t is an escape character that prints tab character in the terminal
    std::cout << "Enter a name for a friend:\n> ";
    std::string friend_name;
    std::cin >> friend_name;
    std::cout << "Have you seen " << friend_name << " lately?\n";
    std::cout << "Enter an age for the recipient:\n> ";
    int age = 0;
    std::cin >> age;
    if (age <= 0) // comparsion operators
        std::cout << "You are kidding!\n";
    if (age >= 110)
        std::cout << "You are kidding!\n";
    // if (age < 12)
    //     std::cout << "Next year you will be " << age + 1;
    // this executes at any number below 12, this will lead to trouble
    if (age < 12 && age > 0)
        std::cout << "Next year you will be " << age + 1 << '\n';
    // this works, check that the numbers is both less thatn 12 and bigger than
    // 0, && means and
    if (age == 17)
        std::cout << "Next year you will be able to vote!\n";
    if (age > 70)
        std::cout << "Are you retired?\n";
    std::cout << "Yours sincerely\n\nyousef.\n";
}
