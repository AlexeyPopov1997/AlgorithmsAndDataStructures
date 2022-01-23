#include <iostream>
#include <vector>


class MergeSort
{
    private:
        static std::vector<unsigned int> merge(std::vector<unsigned int> leftArray, std::vector<unsigned int> rightArray, long& inversionsNumber) {
            std::vector<unsigned int> inversions;
            auto leftArrayPtr = leftArray.begin();
            auto rightArrayPtr = rightArray.begin();
            bool isLeftArrayPtr = false;
            bool isRightArrayPtr = false;

            while (true) {
                if (*leftArrayPtr <= *rightArrayPtr) {
                    inversions.push_back(*leftArrayPtr);
                    leftArrayPtr++;
                    if (leftArrayPtr == leftArray.end()) {
                        isLeftArrayPtr = true;
                        break;
                    }
                }
                else {
                    inversionsNumber += (leftArray.end() - leftArrayPtr);
                    inversions.push_back(*rightArrayPtr);
                    rightArrayPtr++;
                    if (rightArrayPtr == rightArray.end()) {
                        isRightArrayPtr = true;
                        break;
                    }
                }
            }

            if (isLeftArrayPtr) {
                inversions.insert(inversions.end(), rightArrayPtr, rightArray.end());
            } else {
                inversions.insert(inversions.end(), leftArrayPtr, leftArray.end());
            }

            return inversions;
        }

    public:
        static std::vector<unsigned int> mergeSort(std::vector<unsigned int>& arrray, size_t left, size_t right, long& inversionsNumber) {
            if (right == left) {
                std::vector<unsigned int> sortedArray;
                sortedArray.push_back(arrray[right]);
                return sortedArray;
            }

            size_t mid = left + (right - left) / 2;
            return merge(mergeSort(arrray, left, mid, inversionsNumber), mergeSort(arrray, mid + 1, right, inversionsNumber), inversionsNumber);
        }
};


int main()
{
	unsigned int sizeInputArrey = 0;
	std::vector<unsigned int> inputArray;
	std::cin >> sizeInputArrey;

	while (sizeInputArrey-- >= 1) {
		unsigned int valueArray = 0;
		std::cin >> valueArray;
		inputArray.push_back(valueArray);
	}

	long inversionsNumber = 0;

	auto inversions = MergeSort::mergeSort(inputArray, 0, inputArray.size() - 1, inversionsNumber);
	std::cout << inversionsNumber << std::endl;
	
	return 0;
}