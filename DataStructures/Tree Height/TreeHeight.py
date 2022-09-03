class Node:
    def __init__(self, key) -> None:
        self.key = key
        self.parent_key = None
        self.children_list = [] 


class NTree:
    def __init__(self, parents_list) -> None:
        self.__parents_list = parents_list
        self.__nodes_count = len(self.__parents_list)
        self.__nodes = [None for i in range(self.__nodes_count)]
        self.__root = None
        
    def build(self) -> None:
        for i in range(self.__nodes_count):
            self.add_node(i)

    def add_node(self, key) -> None:
        if self.__nodes[key] is not None:
            return

        self.__nodes[key] = Node(key)

        if self.__parents_list[key] == -1:
            self.__root = self.__nodes[key]
            return
        else:
            self.__nodes[key].parent_key = self.__parents_list[key]

        if self.__nodes[self.__parents_list[key]] is None:
            self.add_node(key)

        if self.__nodes[self.__parents_list[key]] is not None:
            self.__nodes[self.__parents_list[key]].children_list.append(self.__parents_list[key])

    def get_children_nodes(self, key):
        return self.__nodes[key].children_list

    
def main():
    parents_list = [9, 7, 5, 5, 2, 9, 9, 9, 2, -1]
    n_tree = NTree(parents_list)
    n_tree.build()

    for i in range(len(parents_list)):
        print(n_tree.get_children_nodes(i))


if __name__ == '__main__':
    main()