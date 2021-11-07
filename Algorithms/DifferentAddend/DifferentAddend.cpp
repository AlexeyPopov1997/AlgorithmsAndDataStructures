#include <map>
#include <vector>
#include <cassert>
#include <iostream>


std::pair<int, std::vector<int>> getDifferentAddendsNumber(int inputNumber) {
    assert(inputNumber >= 1);

    int addendsNumber = 1;
    int addendsSum = 0;
    std::vector<int> addends;

    while (addendsSum <= inputNumber) {
        if (inputNumber <= 2) {
            addends.push_back(inputNumber);
            return {1, addends};
        }

        if (addendsSum + addendsNumber <= inputNumber) {
            addends.push_back(addendsNumber);
            addendsSum += addendsNumber;
            addendsNumber += 1;
        }
        else {
            addendsNumber--;
            while(addendsSum <= inputNumber) {
                if (inputNumber == addendsSum) {
                    return {addendsNumber, addends};
                }

                int removedElement = addends.back();
                addends.pop_back();
                addends.push_back(removedElement + 1);
                addendsSum += 1;
            }

            return {addendsNumber, addends};
        }
    }
}


int main() {
    int inputNumber;
    std::cin >> inputNumber;

    int addendsNumber;
    std::vector<int> addends;

    std::tie(addendsNumber, addends) = getDifferentAddendsNumber(inputNumber);

    std::cout << addendsNumber << std::endl;

    for (int addend: addends) {
       std::cout << addend << ' '; 
    }
    std::cout << std::endl;

    return 0;
}