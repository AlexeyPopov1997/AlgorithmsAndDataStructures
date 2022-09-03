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

        int getParentKey() {
            return parentKey;
        }

    friend class Tree;
};


class Tree {
    private:
        Node root;
        std::vector<Node> nodes;
        int height = 1;

        Node getNode(int key) {
            for (Node node : nodes) {
                if (node.key == key) {
				    return node;
			    }
            }
        }

    public:
        void init(const std::unordered_map<int, int> &parents) {
            for (int key = 0; key < parents.size(); key++) {
                if (parents.at(key) == -1) {
                    this->root = Node(key);
                    this->root.parentKey = key;
                    this->nodes.push_back(this->root);
                } else {
                    Node current = Node(key);
                    current.parentKey = parents.at(key);
                    this->nodes.push_back(current);
                }
            }
        }

        void build() {
            for (Node node : nodes) {
                if (node.data != root.data) {
                    Node parent = getNode(node.getData());
                    parent.children.push_back(node);
                }
            }
        }

        int getHeight() {
            return height;
        }
};


int main() {
    int nodesCount;
    std::cin >> nodesCount;

    std::unordered_map<int, int> parents;
    for (int i = 0; i < nodesCount; i++) {
        int data;
        std::cin >> data;
        parents[i] = data;
    }

    Tree tree;
    tree.init(parents);
    tree.build();
    std::cout << tree.chi() << std::endl;

    return 0;
}