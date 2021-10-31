import random

def test(get_gcd, n_iter=100):
    for i in range(n_iter):
        constant = random.randint(0, 1024)
        number1 = constant * random.randint(0, 128)
        number2 = constant * random.randint(0, 128)
        assert get_gcd(number1, number1) == get_gcd(number1, 0) == number1
        assert get_gcd(number2, number2) == get_gcd(number2, 0) == number2
        assert get_gcd(number1, 1) == get_gcd(number2, 1) == 1
        divider = get_gcd(number1, number2)
        assert number1 % divider == number2 % divider == 0

def get_gcd(number1, number2):
    assert number1 >= 0 and number2 >= 0
    if number1 == 0 or number2 == 0:
        return max(number1, number2)
    return get_gcd(number2 % number1, number1)

def main():
    test(get_gcd)
    print('Enter number1 and number2')
    number1, number2 = map(int, input().split())
    print('GCD : {} \n'.format(get_gcd(number1, number2)))

if __name__ == '__main__':
    main()
