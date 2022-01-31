#include <algorithm>
#include <iostream>
#include <vector>

  
void countSort(std::vector<int>& inputArray) {
    int maxElement = *max_element(inputArray.begin(), inputArray.end());
    int minElement = *min_element(inputArray.begin(), inputArray.end());
    int range = maxElement - minElement + 1;
  
    std::vector<int> countArray(range), outputArray(inputArray.size());

    for (int i = 0; i < inputArray.size(); i++) {
        countArray[inputArray[i] - minElement]++;
    }
  
    for (int i = 1; i < countArray.size(); i++) {
        countArray[i] += countArray[i - 1];
    }
  
    for (int i = inputArray.size() - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i] - minElement] - 1] = inputArray[i];
        countArray[inputArray[i] - minElement]--;
    }
  
    for (int i = 0; i < inputArray.size(); i++) {
        inputArray[i] = outputArray[i];
    }
}


void printArray(std::vector<int>& inputArray) {
    for (int i = 0; i < inputArray.size(); i++)
        std::cout << inputArray[i] << " ";
    std::cout << std::endl;
}


int main()
{
    size_t sizeArray;
    std::cin >> sizeArray;

    std::vector<int> array(sizeArray);
    for (int &element : array) {
        std::cin >> element;
    }

    countSort(array);
    printArray(array);
    return 0;
}