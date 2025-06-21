#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

double calc_mean(std::vector<double> v) {
    double sum = 0;
    for (double i : v) {
        sum += i;
    }
    return sum / v.size();
}

double calc_median(std::vector<double> v) {
    int mid = v.size() / 2;
    double median = 0;
    std::ranges::sort(v);
    if (v.size() % 2 == 1)
        median =  v[mid];
    else {
        median =  (v[mid] + v[mid-1]) / 2;
    }
    return median;
}

int main() {
    // reads temperatures into a vector
    std::vector<double> temps;
    std::cout << "Please enter some temperatures:\n";
    for(double temp; std::cin >> temp;) {
        temps.push_back(temp);
    }
    // calculate mean and median
    std::cout << "the mean is " << calc_mean(temps) << '\n';
    std::cout << "the median is " << calc_median(temps) << '\n';
}
