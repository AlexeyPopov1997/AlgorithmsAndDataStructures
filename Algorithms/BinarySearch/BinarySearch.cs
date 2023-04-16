namespace BinarySearch
{
    public static class BinarySearch
    {
        public static List<int> ParseLine(this string input)
        {
            List<int> list = new();
            
            string[] chars = input.Split(' ');
                
            for(int i = 1; i < chars.Length; i++)
            {
                list.Add(int.Parse(chars[i]));
            }

            return list;
        }

        public static int GetPosition(List<int> numbers, int number)
        {
            int low = 0;
            int high = numbers.Count - 1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (numbers[mid] == number)
                {
                    return mid + 1;
                }

                if (numbers[mid] < number)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            return -1;
        }

        public static void Main()
        {
            string? input = Console.ReadLine();
            List<int> numbers = input.ParseLine();
            
            numbers.Sort();

            input = Console.ReadLine();
            List<int> query = input.ParseLine();

            query.ForEach(x => Console.Write("{0} ", GetPosition(numbers, x)));
        }
    }
}