from functools import lru_cache 

# Recursion Implementation of obtaining the fibonacci number (Limit for 1000 recursive calls) 
@lru_cache(maxsize=None)
def get_fib_number_with_recursion(number):
    assert number >= 0
    return number if number <= 1 else get_fib_number_with_recursion(number - 1) + get_fib_number_with_recursion(number - 2)

# Effective implementation of obtaining the fibonacci number
def get_fib_number(number):
    assert number >= 0
    number1, number2 = 0, 1
    for i in range(number - 1):
        number1, number2 = number2, number1 + number2
    return number2

# Function for getting a last digit fibonacci number
def get_last_digit_fib_number(func):
    return func % 10

# Function for for getting a remainder of the division of the fibonacci number by the number
def get_fib_number_div_remainder(func, divider):
    return func % divider

def main():
    number = 80
    print('*** Recursion Implementation ***')
    print(' Number = {}; Fibonacci Number =  {} \n'.format(number, get_fib_number_with_recursion(number)))

    number = 8000
    print('*** Effective Implementation ***')
    print(' Number = {}; Fibonacci Number =  {} \n'.format(number, get_fib_number(number)))

    print(' Number = {}; Last Digit Fibonacci Number =  {} \n'.format(number, get_last_digit_fib_number(get_fib_number(number))))

    divider = 12345
    print(' Number = {}; Remainder of the Division of the Fibonacci Number =  {} \n'.format(number, get_fib_number_div_remainder(get_fib_number(number), divider)))
    
if __name__ == '__main__':
    main()
