#include <cassert>
#include <iostream>

class FibonacciNumber final {
    public:
        // Method for getting a huge fibonacci number
        static uint64_t getNumber(int number) {
            assert(number >= 0);

            if (number <= 1) {
                return number;
            }

            uint64_t previosNumer = 0;
            uint64_t currentNumber = 1;
            for(int i = 2; i <= number; i++) {
                uint64_t newCurrentNumber = previosNumer + currentNumber;
                previosNumer = currentNumber;
                currentNumber = newCurrentNumber;
            }

            return currentNumber;
        }

        // Method for getting a last digit huge fibonacci number
        static uint64_t getLastDigitFibonacciNumber(int number) {
            return (getNumber(number) % 10);
        }

        // Method for getting a remainder of the division of the fibonacci number by the number
        static uint64_t getFibonacciNumberDivRemainder(int number, int divider) {
            return (getNumber(number) % divider);
        }
};

int main() {
    int number;
    int divider;

    std::cout << "Enter number: " << std::endl; 
    std::cin >> number;
    std::cout << "Number: " << number << "; Fibonacci Number: " << FibonacciNumber::getNumber(number) << std::endl;
    std::cout << "Number: " << number << "; Last Digit Fibonacci Number: " << FibonacciNumber::getLastDigitFibonacciNumber(number) << std::endl;

    std::cout << "Enter divider: " << std::endl;
    std::cin >> divider;
    std::cout << "Number: " << number << "; Remainder of the Division of the Fibonacci Number: " << FibonacciNumber::getFibonacciNumberDivRemainder(number, divider) << std::endl;
    return 0;
}