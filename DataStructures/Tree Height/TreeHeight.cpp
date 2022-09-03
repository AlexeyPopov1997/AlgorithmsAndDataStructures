#include<iostream>
#include<unordered_map>
#include<vector>


class Node {
    private:
        int key;
        int parentKey;
        std::vector<Node> children;

        Node() {}

        Node(int key) {
            this->key = key;
        }

    friend class Tree;
};


class Tree {
    private:
        Node root;
        std::vector<Node> nodes;

    public:
        Tree() {}

        Tree(std::unordered_map<int, int> parents) {
            for (int key = 0; key < parents.size(); key++) {
                std::cout << key << " " << parents.at(key) << "\n";
            }
        }
};


int main() {
    int nodesCount;
    std::cin >> nodesCount;

    std::unordered_map<int, int> parents;

    for (int i = 0; i < nodesCount; i++) {
        int input;
        std::cin >> input;
        parents[i] = input;
    }

    Tree tree(parents);

    return 0;
}