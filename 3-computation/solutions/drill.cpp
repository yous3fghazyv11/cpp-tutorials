#include <iostream>
#include <limits>
#include <string>
#include <vector>

std::string transform(std::string s);
void clear_istream();
bool valid_unit(std::string unit);
std::string check_input(double num, std::string unit);
double convert_to_m(double num, std::string unit);
double min_element(std::vector<double> v);
double max_element(std::vector<double> v);

std::string transform(std::string input_string) {
    std::string r;
    for (char input_char : input_string) {
        int temp = input_char;
        if (temp < 97) {
            char output_char = temp + 32;
            r += output_char;
        } else {
            r += temp;
        }
    }
    return r;
}

double min_element(std::vector<double> v) {
    double min = std::numeric_limits<double>::max();
    for (double i : v) {
        if (i < min)
            min = i;
    }
    return min;
}

double max_element(std::vector<double> v) {
    double max = std::numeric_limits<double>::min();
    for (double i : v) {
        if (i > max)
            max = i;
    }
    return max;
}

void clear_istream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool valid_unit(std::string unit) {
    std::vector<std::string> valid_units = {"cm", "in", "m", "ft"};
    for (std::string u : valid_units) {
        if (unit == u)
            return true;
    }
    return false;
}

std::string check_input(double num, std::string unit)
// we could've made this function a simple bool that returns true if input good,
// or false if input bad however we want to also check for eof aswell
{
    if (!std::cin) {
        if (std::cin.eof()) {
            return "eof";
        }
        return "bad";
    }
    if (num <= 0) {
        return "bad";
    }
    unit = transform(unit);
    if (valid_unit(unit)) {
        return "success";
    }
    return "bad";
}

double convert_to_m(double num, std::string unit) {
    if (unit == "cm") {
        return num * 0.01;
    } else if (unit == "ft") {
        return num * 0.3048;
    } else if (unit == "in") {
        return num * 0.0254;
    } else {
        return num;
    }
}

int main() {
    // definitions
    double value;
    std::string unit;
    std::vector<double> values;
    std::vector<std::string> units;
    std::vector<double> values_in_m;
    // main loop
    while (std::cout << "> ") {
        // getting input
        std::cin >> value >> unit;
        std::string status = check_input(value, unit);
        if (status == "bad") {
            clear_istream();
            std::cerr << "Bad input\n";
            continue;
        } else if (status == "eof") {
            std::cout << "\nExiting...\n";
            break;
        }
        unit = transform(unit);
        values.push_back(value);
        units.push_back(unit);
        double value_in_m = convert_to_m(value, unit);
        // computing output
        if (values_in_m.empty()) {
            std::cout << "This is the first value entered\n";
        } else {
            if (value_in_m < min_element(values_in_m)) {
                std::cout << "This is the smallest so far!\n";
            }
            if (value_in_m > max_element(values_in_m)) {
                std::cout << "This is the largest so far!\n";
            }
        }
        values_in_m.push_back(value_in_m);
    }
    // printing out original values and units;
    std::cout << "Values entered: [";
    for (size_t i = 0; i < values.size(); i++) {
        std::cout << values[i] << units[i];
        if (i != (values.size() - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
    // printing out sum in meters
    std::cout << "sum of values in meter: ";
    double result = 0;
    for (double value : values_in_m) {
        result += value;
    }
    std::cout << result << "m\n";
    return 0;
}
