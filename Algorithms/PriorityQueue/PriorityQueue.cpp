#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

template <typename Item>
class PriorityQueue {
    private:
        std::priority_queue<Item> queue;
        std::vector<Item> extractedCache;

    public:
        void push(int priority) {
            queue.push(priority);
        }

        void pop() {
            extractedCache.push_back(queue.top());
            queue.pop();
        }

        std::pair<std::string, int> parseCommand(std::string line, std::string delimiter) {
            std::string command;
            int priority;

            auto start = 0U;
            auto end = line.find(delimiter);

            while (end != std::string::npos) {
                command = line.substr(start, end - start);
                start = end + delimiter.length();
                end = line.find(delimiter, start);
            }

            if (line != "ExtractMax") {
                priority = std::stoi(line.substr(start, end));
            } else {
                priority = 0;
            }
            
            return {command, priority};
        }

        void printExtractedCache() {
            for (auto item : extractedCache) {
                std::cout << item << std::endl;
            }
        }
};

int main() {
    int commandsNumber;
    std::cin >> commandsNumber;
    PriorityQueue<int> priorityQueue;

    for (int i = 0; i <= commandsNumber; i++) {
        std::string line;
        std::getline(std::cin, line);

        std::string command;
        int priority;
        if (!line.empty()) {
            std::tie(command, priority) = priorityQueue.parseCommand(line, " ");
            if (command == "Insert") {
                priorityQueue.push(priority);
            } else {
                priorityQueue.pop();
            }
        }
    }

    priorityQueue.printExtractedCache();
    
    return 0;
}