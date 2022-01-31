def count_sort(imput_array, values_range, size_array):
    count_array = []
    output_array = []

    for i in range(values_range):
        count_array.append(0)

    for i in range(size_array):
        output_array.append(0)
        count_array[imput_array[i] - 1] = count_array[imput_array[i] - 1] + 1

    for i in range(1, values_range, 1):
        count_array[i] = count_array[i] + count_array[i - 1]

    for i in range(size_array - 1, -1, -1):
        output_array[count_array[imput_array[i] - 1] - 1] = imput_array[i]
        count_array[imput_array[i] - 1] = count_array[imput_array[i] - 1] - 1

    return output_array


def main():
    size_array = int(input())
    array = [int(i) for i in input().split()]

    output = count_sort(array, 10, size_array)

    for i in range(size_array):
        if i < size_array-1:
            print(output[i], end=' ')
        else:
            print(output[i])


if __name__ == '__main__':
    main()
