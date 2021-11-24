#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

class Huffman{
    struct CharSetFrequency {
        std::string charSet;
        int frequency;

        bool operator < (const CharSetFrequency &otherSet) const {
            return std::tie(frequency, charSet) > std::tie(otherSet.frequency, otherSet.charSet);
        }
    };

public:
    static std::unordered_map<char, std::string> encode(const std::string &inputText) {
        std::unordered_map<char, int> charFrequencies;
        for (auto chr : inputText) {
            charFrequencies[chr]++;
        }

        std::vector<CharSetFrequency> frequencies;
        for (auto charFrequency : charFrequencies) {
            frequencies.push_back({std::string(1, charFrequency.first), charFrequency.second});
        }

        if (frequencies.size() == 1) {
            std::unordered_map<char, std::string> result;
            result[frequencies[0].charSet[0]] = "0";
            return result;
        }

        std::unordered_map<char, std::string> result;
        std::priority_queue<CharSetFrequency> queue(frequencies.begin(), frequencies.end());
        while (queue.size() >= 2) {
            auto first = queue.top();
            queue.pop();

            auto second = queue.top();
            queue.pop();

            for (auto chr : first.charSet) {
                result[chr] = "0" + result[chr];
            }

            for (auto chr : second.charSet) {
                result[chr] = "1" + result[chr];
            }

            queue.push({first.charSet + second.charSet, first.frequency + second.frequency});
        }
        return result;
    }

    static std::string decode(const std::string &inputText, const std::unordered_map<char, std::string> &encoding) {
        size_t len = inputText.size();
        size_t position = 0;
        std::string result;

        while (position < len) {
            for (auto &encoded : encoding) {
                if(inputText.substr(position, encoded.second.size()) == encoded.second) {
                    result += encoded.first;
                    position += encoded.second.size();
                    break;
                }
            }
        }

        return result;
    }

    static std::unordered_map<char, int> getEncodingValues(std::string line, std::string delimiter) {
        std::unordered_map<char, int> encodingValues;

        auto start = 0U;
        auto end = line.find(delimiter);

        while (end != std::string::npos) {
            encodingValues[[], []] = line.substr(start, end - start)[0];
            start = end + delimiter.length();
            end = line.find(delimiter, start);
        }

        code = stoi(line.substr(start, end));
        
        return {letter, code};
    }
};

int main(){
    /*
    std::string inputText;
    std::cin >> inputText;

    auto encoding = Huffman::encode(inputText);

    std::string encodedText;
    for (auto chr : inputText) {
        encodedText += encoding[chr];
    }

    std::cout << encoding.size() << " " << encodedText.size() << std::endl;
    
    for (auto &encoded : encoding){
        std::cout << encoded.first << ": " << encoded.second << std::endl;
    }
    std::cout << encodedText << std::endl;
    */

    int letterAmount;
    int stringLen;

    std::vector<char> letters;

    std::cin >> letterAmount >> stringLen;
    std::cout << letterAmount << " " << stringLen << std::endl;

    std::string line;

    for (int i = 0; i < letterAmount; i++) {
        std::cin >> line;
        char letter;
        int code;
        std::tie(letter, code) = Huffman::getEncodingValues(line, ": ");
    }

    return 0;
}