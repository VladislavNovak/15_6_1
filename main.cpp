// Интересно: accumulate, for_each, distance
#include <iostream>
#include <vector>
#include <numeric> // std::accumulate
#include <algorithm> // std::for_each

using std::vector;

vector<int>::const_iterator getFirstIt(vector<int> (&arr)) {
    int max = 0;

    vector<int>::const_iterator currentIt;

    for (auto shift = arr.cbegin(); shift < arr.cend(); ++shift) {
        int sum = std::accumulate(shift, arr.cend(), 0);
        if (sum > max) {
            max = sum;
            currentIt = shift;
        }
    }

    return currentIt;
}

vector<int>::const_iterator getLastIt(vector<int> (&arr)) {
    int max = 0;

    auto currentIt = arr.cend();

    for (auto shift = arr.cend(); shift > arr.begin(); --shift) {
        int sum = std::accumulate(arr.cbegin(), shift, 0);
        if (sum > max) {
            max = sum;
            currentIt = shift;
        }
    }

    return currentIt;
}

void report(vector<int> (&arr), vector<int>::const_iterator firstIt, vector<int>::const_iterator lastIt) {
    std::cout << "First index:: " << std::distance(arr.cbegin(), firstIt) << std::endl;
    std::cout << "Last index::  " << std::distance(arr.cbegin(), lastIt - 1) << std::endl;

    std::cout << "Values:: ";
    std::for_each(firstIt, lastIt, [&](const auto &i) {
        std::cout << i << " ";
    });
    std::cout << "\n----------------" << std::endl;
}

int main() {
    vector<vector<int>> mass = {
            { -2, 1, -3, 4, -1, 2, 1, -5, 4},
            { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84}
    };

    for (auto arr : mass) {
        auto firstIt = getFirstIt(arr);
        auto lastIt = getLastIt(arr);

        report(arr, firstIt, lastIt);
    }
}