import sys


class MergeSort:
    def __init__(self):
        self.__inversions_count = 0

    def merge(self, left_array, right_array):
        inversions = []
        while left_array and right_array:
            if left_array[0] <= right_array[0]:
                inversions.append(left_array.pop(0))
            else:
                self.__inversions_count += len(left_array)
                inversions.append(right_array.pop(0))
        inversions.extend(left_array or right_array)
        return inversions

    def merge_sort(self, array):
        if len(array) > 1:
            mid = len(array) // 2
            return self.merge(self.merge_sort(array[:mid]), self.merge_sort(array[mid:]))
        return array
    
    def print_inversions_count(self):
        print(self.__inversions_count)


def main():
  reader = (map(int, line.split()) for line in sys.stdin)
  next(reader)
  array = list(next(reader))

  merge_sort = MergeSort()
  merge_sort.merge_sort(array)
  merge_sort.print_inversions_count()


if __name__ == "__main__":
    main()