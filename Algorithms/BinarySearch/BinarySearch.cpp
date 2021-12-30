#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int getPosition(const std::vector<int> &numbers, int number) {
    size_t low = 0;
    size_t high = numbers.size() - 1;

    while (low <= high) {
        size_t mid = low + (high - low) / 2;

        if (numbers[mid] == number) {
            return mid + 1;
        }

        if (numbers[mid] < number) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    size_t numberCount;
    std::cin >> numberCount;
    std::vector<int> numbers(numberCount);
    for (auto &number:numbers) {
        std::cin >> number;
    }

    assert(std::is_sorted(numbers.begin(), numbers.end()));

    size_t queryCount;
    std::cin >> queryCount;
    while (queryCount-- > 0) {
        int number;
        std::cin >> number;
        std::cout << getPosition(numbers, number) << " ";
    }
    std::cout << std::endl;

    return 0;
}