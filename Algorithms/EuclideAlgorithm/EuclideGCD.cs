using System.Diagnostics;


namespace EuclideGCD
{
    public static class EuclideGCD
    {
        public static (int, int) ParseInput(this string input)
        {
            string[] chars = input.Split(' ');
            return (int.Parse(chars[0]), int.Parse(chars[1]));
        }

        public static int GetGCD(int number1, int number2)
        {
            Debug.Assert(number1 > 0);

            if (number2 > 0)
            {
                return GetGCD(number2, number1 % number2);
            }

            return number1;
        }

        public static void Main()
        {
            string? input = Console.ReadLine();
            (int number1, int number2) = input.ParseInput();
            Console.WriteLine(GetGCD(number1, number2));
        }
    }
}