#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

class Huffman{
    struct SymbolSetFrequency {
        std::string symbolSet;
        int frequency;

        bool operator < (const SymbolSetFrequency &otherSet) const {
            return std::tie(frequency, symbolSet) > std::tie(otherSet.frequency, otherSet.symbolSet);
        }
    };

public:
    static std::unordered_map<char, std::string> encode(const std::string &inputCode) {
        std::unordered_map<char, int> symbolFrequencies;
        for (auto symbol : inputCode) {
            symbolFrequencies[symbol]++;
        }

        std::vector<SymbolSetFrequency> frequencies;
        for (auto symbolFrequency : symbolFrequencies) {
            frequencies.push_back({std::string(1, symbolFrequency.first), symbolFrequency.second});
        }

        if (frequencies.size() == 1) {
            std::unordered_map<char, std::string> outputCode;
            outputCode[frequencies[0].symbolSet[0]] = "0";
            return outputCode;
        }

        std::unordered_map<char, std::string> outputCode;
        std::priority_queue<SymbolSetFrequency> queue(frequencies.begin(), frequencies.end());
        while (queue.size() >= 2) {
            auto first = queue.top();
            queue.pop();

            auto second = queue.top();
            queue.pop();

            for (auto symbol : first.symbolSet) {
                outputCode[symbol] = "0" + outputCode[symbol];
            }

            for (auto symbol : second.symbolSet) {
                outputCode[symbol] = "1" + outputCode[symbol];
            }

            queue.push({first.symbolSet + second.symbolSet, first.frequency + second.frequency});
        }
        return outputCode;
    }

    static std::string decode(const std::string &inputCode, const std::unordered_map<std::string, char> &decodingDescpiption) {
        std::string currentCode;
        std::string outputCode = "";
        for (auto ch: inputCode) {
            currentCode += ch;
            if(decodingDescpiption.find(currentCode) != decodingDescpiption.end()) {
                outputCode += decodingDescpiption.at(currentCode);
                currentCode.erase();
            }
        }
        return outputCode;
    }

    static std::pair<std::string, char> getDecodingDescpiption(std::string line, std::string delimiter) {
        char letter;
        std::string code;

        auto start = 0U;
        auto end = line.find(delimiter);

        while (end != std::string::npos) {
            letter = line.substr(start, end - start)[0];
            start = end + delimiter.length();
            end = line.find(delimiter, start);
        }

        code = line.substr(start, end);
        
        return {code, letter};
    }
};

int main(){
    const std::string MODE = "DECODING"; // "ENCODING" or "DECODING"

    if (MODE == "ENCODING") {
        std::string inputCode;
        std::cin >> inputCode;

        auto encodingDescription = Huffman::encode(inputCode);

        std::string outputCode;
        for (auto symbol : inputCode) {
            outputCode += encodingDescription[symbol];
        }

        std::cout << encodingDescription.size() << " " << outputCode.size() << std::endl;
        
        for (auto &encoded : encodingDescription){
            std::cout << encoded.first << ": " << encoded.second << std::endl;
        }
        std::cout << outputCode << std::endl;
    } else {
        int lettersNum;
        int lineLength;

        std::cin >> lettersNum >> lineLength;

        std::unordered_map<std::string, char> decodingDescription;

        for (int i = 0; i <= lettersNum; i++) {
            std::string line;
            std::getline(std::cin, line);
            char letter;
            std::string code;
            if (!line.empty()) {
                std::tie(code, letter) = Huffman::getDecodingDescpiption(line, ": ");
                decodingDescription.insert(std::pair<std::string, char>(code, letter));
            }
        }

        std::string inputCode;
        std::cin >> inputCode;

        std::cout << Huffman::decode(inputCode, decodingDescription) << std::endl;
    }

    return 0;
}