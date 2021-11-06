#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

struct Item final {
  int weight;
  int value;
};

double getMaxKnapsackValue(int capacity, std::vector <Item> items) {
  double value = 0.0;

  // take items while there is empty space in knapsack
  for (auto &item:items) {
    if (capacity > item.weight) {
      // can take full item and continue
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