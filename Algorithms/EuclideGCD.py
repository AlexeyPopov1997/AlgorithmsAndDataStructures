def findGCD(a, b):
    if (a == 0):
        return b
    elif (b == 0):
        return a
    elif (a >= b):
        return findGCD(a % b, b)
    elif (b >= a):
        return findGCD(a, b % a)


def main():
    a, b = map(int, input().split())
    print(findGCD(a, b))


if __name__ == "__main__":
    main()