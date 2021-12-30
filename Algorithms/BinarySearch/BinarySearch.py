from bisect import bisect_left


def get_position(numbers, number):
    low = bisect_left(numbers, number)
    if low != len(numbers) and numbers[low] == number:
        return low + 1
    else:
        return -1


def main():
    _, *numbers = map(int, input().split())
    _, *query = map(int, input().split())
    print(*[get_position(numbers, key) for key in query])


if __name__ == "__main__":
    main()
