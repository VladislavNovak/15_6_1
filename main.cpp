// Интересно: accumulate, for_each, distance
#include <iostream>
#include <vector>
#include <numeric> // std::accumulate
#include <algorithm> // std::for_each

using std::vector;

vector<int>::const_iterator getIt(vector<int> &arr, bool needFirstIt) {
    int max = 0;

    vector<int>::const_iterator currentIt;
    vector<int>::const_iterator startIt;
    vector<int>::const_iterator endIt;

    startIt = needFirstIt ? arr.cbegin() : arr.cend();
    endIt = needFirstIt ? arr.cend() : arr.cbegin();

    while((needFirstIt ? ++startIt : --startIt) != endIt) {
        auto a = needFirstIt ? startIt : endIt;
        auto b = needFirstIt ? endIt : startIt;
        int sum = std::accumulate(a, b, 0);
            if (sum > max) {
                max = sum;
                currentIt = startIt;
            }
    }

    return currentIt;
}

vector<int>::const_iterator getFirstIt(vector<int> &arr) {
    return getIt(arr, true);
}

vector<int>::const_iterator getLastIt(vector<int> &arr) {
    return getIt(arr, false);
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