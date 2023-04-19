namespace CountSort
{
    public static class CountSort
    {
        public static List<int> ParseLine(string input)
        {
            List<int> list = new();

            string[] chars = input.Split(' ');

            for (int i = 0; i < chars.Length; i++)
            {
                list.Add(int.Parse(chars[i]));
            }

            return list;
        }

        public static void Sort(this List<int> list)
        {
            int maxElement = list.Max();
            int minElement = list.Min();
            int range = maxElement - minElement + 1;

            List<int> countList = new();
            List<int> outputList = new();

            list.ForEach(x => countList[x - minElement]++);

            for (int i = 1; i < countList.Count; i++)
            {
                countList[i] += countList[i - 1];
            }

            for (int i = list.Count - 1; i >= 0; i--)
            {
                outputList[countList[list[i] - minElement] - 1] = list[i];
                countList[list[i] - minElement]--;
            }

            for (int i = 0; i < list.Count; i++)
            {
                list[i] = outputList[i];
            }
        }

        public static void Print(this List<int> array)
        {
            array.ForEach(x => Console.Write("{0} ", x));
        }

        public static void Main()
        {
            int sizeArray = int.Parse(Console.ReadLine());
            List<int> list = ParseLine(Console.ReadLine());

            list.Sort();
            list.Print();
        }
    }
}