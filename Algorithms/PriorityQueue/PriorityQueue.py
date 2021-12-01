class PriorityQueue:
    def __init__(self):
        self.__queue = []
        self.__index = 0
    
    def push(self, item, priority):
        from heapq import heappush
        heappush(self.__queue, (-priority, self.__index, item))
        self.__index += 1

    def pop(self):
        from heapq import heappop
        return heappop(self.__queue)[-1]


def main():
    commands_num = int(input())
    priority_queue = PriorityQueue()
    extracted_items = []

    for _ in range(commands_num):
        commamd = input()
        if commamd.startswith("Insert"):
            _, item = commamd.split()
            priority = item = int(item)
            priority_queue.push(item, priority)
        else:
            extracted_items.append(priority_queue.pop())

    for extracted_item in extracted_items:
        print(extracted_item)


if __name__ == '__main__':
    main()
