#include <cmath>
#include <iostream>

int main() {
    std::cout << "Simple program to solve the equation: ax^2 + bx + c = 0\n";
    std::cout << "enter the values for a, b, c respectively:\n> ";
    double a, b, c;
    std::cin >> a >> b >> c;
    double x1 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
    double x2 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);
    std::cout << "x1 = " << x1 << '\n';
    std::cout << "x2 = " << x2 << '\n';
}
