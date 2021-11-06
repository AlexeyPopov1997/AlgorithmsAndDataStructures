#include <vector>
#include <iostream>
#include <algorithm> 

struct Item final {
  int weight;
  int value;
};

bool sortByItemProfit(const Item &firstItem, const Item &secondItem) {
  return static_cast<std::int64_t>(firstItem.weight) * secondItem.value < static_cast<std::int64_t>(secondItem.weight) * firstItem.value;
}

double getMaxKnapsackValue(int capacity, std::vector <Item> items) {
  std::sort(items.begin(), items.end(), sortByItemProfit);
  
  double value = 0.0;

  for (auto &item:items) {
    if (capacity > item.weight) {
      capacity -= item.weight;
      value += item.value;
    } else {
      value += item.value * (static_cast <double>(capacity) / item.weight);
      break;
    }
  }

  return value;
}

int main(void) {
  int itemsNumber;
  int knapsackCapacity;
  std::cin >> itemsNumber >> knapsackCapacity;
  std::vector <Item> items(itemsNumber);
  for (int i = 0; i < itemsNumber; i++) {
    std::cin >> items[i].value >> items[i].weight;
  }

  double maxKnapsackValue = getMaxKnapsackValue(knapsackCapacity, std::move(items));

  std::cout.precision(10);
  std::cout << maxKnapsackValue << std::endl;
  return 0;
}