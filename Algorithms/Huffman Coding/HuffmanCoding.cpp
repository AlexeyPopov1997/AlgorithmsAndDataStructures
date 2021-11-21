#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cassert>

class Huffman {
    struct CharFrequency
    {
        char ch;
        int frequency;

        bool operator < (const CharFrequency &other) const {
            return std::tie(frequency, ch) > std::tie(other.frequency, other.ch);
        }
    };

    // Input array must be sorted by frequency
    // Sum of all frequencies must be passed in total_frequency
    static std::unordered_map<char, std::string> shannon_fano_encode(const std::vector<CharFrequency> &frequencies, int totalFrequency) {
        size_t size = frequencies.size();
        std::unordered_map<char, std::string> result;
        if (size <= 1) {
            for (auto &frequency:frequencies) {
                result[frequency.ch] = "";
            }
            return std::move(result);
        }

        // Greedy split frequencies into two parts with approximately equal total frequency
        size_t splitPosition;
        int firstPartFrequency = 0;
        for (splitPosition = 0; splitPosition < size; splitPosition++) {
            int currentFrequency = frequencies[splitPosition].frequency;
            if (firstPartFrequency >= totalFrequency - (firstPartFrequency + currentFrequency)) {
                // Adding current character increases difference between part frequencies
                break;
            }
            firstPartFrequency += currentFrequency;
        }
        assert(splitPosition <= size);

        // Merge part results
        for (auto &encoded:shannon_fano_encode({frequencies.begin(), frequencies.begin() + splitPosition}, firstPartFrequency)) {
            result[encoded.first] = "0" +encoded.second;
        }
        for (auto &encoded:shannon_fano_encode({frequencies.begin() + splitPosition, frequencies.end()}, totalFrequency - firstPartFrequency)) {
            result[encoded.first] = "1" +encoded.second;
        }
        return std::move(result);
    }

    public:
        static std::unordered_map<char, std::string> encode(const std::string &inputText) {
            std::unordered_map<char, int> char_frequencies;
            for (auto ch:inputText) {
                char_frequencies[ch]++;
            }

            std::vector<CharFrequency> frequencies;
            for (auto char_frequency:char_frequencies) {
                frequencies.push_back({char_frequency.first, char_frequency.second});
            }
            std::sort(frequencies.begin(), frequencies.end());

            if (frequencies.size() == 1) {
                // Cannot return empty encoding so this case need to be considered separately
                std::unordered_map<char, std::string> result;
                result[frequencies[0].ch] = '0';
                return result;
            }

            return shannon_fano_encode(std::move(frequencies), static_cast<int>(inputText.size()));
        }

        static std::string decode(const std::string &inputText, const std::unordered_map<char, std::string> &encodedText) {

        }
};

int main() {
    std::string inputText;
    std::cin >> inputText;

    auto encoding = Huffman::encode(inputText);

    std::string encodedText;
    for (auto ch:inputText) {
        encodedText += encoding[ch];
    }
    std::cout << encoding.size() << ' ' << encodedText.size() << std::endl;
    for (auto &encoded: encoding) {
        std::cout << encoded.first << ": " << encoded.second << std::endl;
    }
    std::cout << encodedText << std::endl;

    return 0;
}