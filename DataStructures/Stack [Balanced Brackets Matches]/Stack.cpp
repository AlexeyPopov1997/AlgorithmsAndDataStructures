#include <stack>
#include <string>
#include <set>
#include <iostream>


bool isOpeningBracket(char bracket) {
    std::set<char> openingBrackets = {'(', '[', '{'};
    if (openingBrackets.find(bracket) != openingBrackets.end()) {
        return true;
    } else {
        return false;
    }
}


bool isClosingBracket(char bracket) {
    std::set<char> closingBrackets = {')', ']', '}'};
    if (closingBrackets.find(bracket) != closingBrackets.end()) {
        return true;
    } else {
        return false;
    }
}


bool isMatchingBrackets(char openingBracket, char closingBracket)
{
    return (openingBracket == '{' && closingBracket == '}') || (openingBracket == '(' && closingBracket == ')') || (openingBracket == '[' && closingBracket == ']');
}


std::pair<bool, size_t> isBalancedBrackets(const std::string& inputString) {
    std::stack<std::pair<char, size_t>> bracketsStack;
    size_t stackTopIndex = 0;

    for (const auto inputChar: inputString) {
        ++stackTopIndex;

        if (isOpeningBracket(inputChar)) {
            bracketsStack.push(std::make_pair(inputChar, stackTopIndex));
        }

        if (isClosingBracket(inputChar)) {
            if (bracketsStack.empty()) {
                return std::make_pair(false, stackTopIndex);
            }

            auto top = bracketsStack.top();
            
            if (isMatchingBrackets(top.first, inputChar)) {
                bracketsStack.pop();
            } else {
                return std::make_pair(false, stackTopIndex);
            }
        }
    }

    if (bracketsStack.empty()) {
        return std::make_pair(true, 0);
    } else {
        return std::make_pair(false, bracketsStack.top().second);
    }
}


int main() {
    std::string inputString;
    std::cin >> inputString;

    std::pair<bool, size_t> result = isBalancedBrackets(inputString);
    if (result.first) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << result.second << std::endl;
    }

    return 0;
}