def fib_digit(n):
    fib_digit = []
    fib_digit.append(0)
    fib_digit.append(1)
    for i in range(2, n+1):
        fib_digit.append((fib_digit[i-1] + fib_digit[i-2])%10)
    return fib_digit[n]


def main():
    n = int(input())
    print(fib_digit(n))


if __name__ == "__main__":
    main()