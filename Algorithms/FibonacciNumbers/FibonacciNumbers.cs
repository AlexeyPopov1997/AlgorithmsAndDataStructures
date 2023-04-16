using System.Diagnostics;


namespace FibonacciNumber
{
    public class FibonacciNumber
    {
        // Method for getting a huge fibonacci number
        public static int GetNumber(int number)
        {
            Debug.Assert(number >= 0);

            if (number <= 1) return number;

            int previosNumer = 0;
            int currentNumber = 1;
            for (int i = 2; i <= number; i++)
            {
                int newCurrentNumber = previosNumer + currentNumber;
                previosNumer = currentNumber;
                currentNumber = newCurrentNumber;
            }

            return currentNumber;
        }

        // Method for getting a last digit huge fibonacci number
        public static int GetLastDigitFibonacciNumber(int number)
        {
            return (GetNumber(number) % 10);
        }

        // Method for getting a remainder of the division of the fibonacci number by the number
        public static int GetFibonacciNumberDivRemainder(int number, int divider)
        {
            return (GetNumber(number) % divider);
        }

        public static void Main()
        {
            Console.WriteLine("Enter number:");
            int number = Convert.ToInt32(Console.ReadLine());
            
            Console.WriteLine($"Number: \"{number}\"; Fibonacci Number: \"{GetNumber(number)}\"");
            Console.WriteLine($"Number: \"{number}\"; Last Digit Fibonacci Number: \"{GetLastDigitFibonacciNumber(number)}\"");

            Console.WriteLine("Enter divider:");
            int divider = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"Number: \"{number}\"; Remainder of the Division of the Fibonacci Number: \"{GetFibonacciNumberDivRemainder(number, divider)}\"");
        }
    }
}