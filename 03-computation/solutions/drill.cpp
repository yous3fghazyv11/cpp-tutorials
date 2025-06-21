#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>


bool valid_unit(std::string unit);
bool valid_input(double num, std::string unit);
double convert_to_m(double num, std::string unit);
double min_element(std::vector<double> v);
double max_element(std::vector<double> v);

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

bool valid_input(double num, std::string unit)
{
    if (num <= 0) { 
        return false;
    }
    const std::vector<std::string> valid_units = {"cm", "in", "m", "ft"};
    for (std::string u : valid_units) {
        if (unit == u)
            return true;
    }
    return false;
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
    double ivalue;
    std::string iunit;
    std::vector<double> values;
    std::vector<std::string> units;
    std::vector<double> converted_values;
    // input loop
    while (std::cin >> ivalue >> iunit) {
        if (!valid_input(ivalue, iunit)) {
            std::cerr << "Bad input\n";
            continue;
        }
        values.push_back(ivalue);
        units.push_back(iunit);
        double ivalue_in_m = convert_to_m(ivalue, iunit);
        // computing output
        if (converted_values.empty()) {
            std::cout << "This is the first value entered\n";
        } else {
            if (ivalue_in_m < min_element(converted_values)) {
                std::cout << "This is the smallest so far!\n";
            }
            if (ivalue_in_m > max_element(converted_values)) {
                std::cout << "This is the largest so far!\n";
            }
        }
        converted_values.push_back(ivalue_in_m);
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
    // printing out values converted to meter
    std::cout << "Values in meters: [";
    std::ranges::sort(converted_values);
    for (int i = 0; i < converted_values.size(); ++i) {
        std::cout << converted_values[i] << (i + 1 == converted_values.size() ? "m" : "m, ");
    }
    std::cout << "]\n";
    // printing out sum in meters
    std::cout << "sum of values in meter: ";
    double sum_in_m = 0;
    for (double converted_value : converted_values) {
        sum_in_m += converted_value;
    }
    std::cout << sum_in_m << "m\n";
    return 0;
}
