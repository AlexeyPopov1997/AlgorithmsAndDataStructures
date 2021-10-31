#include <iostream>
#include <cassert>

template <class Int>
Int getGCD(Int number1, Int number2) {
    assert(number1 > 0);

    if (number2 > 0) {
        return getGCD(number2, number1 % number2);
    }
    return number1;
}

int main() {
    std::uint64_t number1, number2;
    std::cout << "Enter number1 and number2" << std::endl;
    std::cin >> number1 >> number2;
    std::cout << "GCD : " << getGCD(number1, number2) << std::endl;
    return 0;
}