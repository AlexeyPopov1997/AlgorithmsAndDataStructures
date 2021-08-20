def fib_mod(n, m):
    fib_prev = 0
    fib = 1
    cached = [fib_prev, fib]
    
    for curr in range(1, n):
        fib_old = fib
        fib = (fib + fib_prev) % m
        fib_prev = fib_old

        if fib_prev == 0 and fib == 1:
            cached.pop()
            break
        else:
            cached.append(fib)
            
    offset = n % len(cached)
    return str(cached[offset])


def main():
    n, m = map(int, input().split())
    print(fib_mod(n, m))


if __name__ == "__main__":
    main()