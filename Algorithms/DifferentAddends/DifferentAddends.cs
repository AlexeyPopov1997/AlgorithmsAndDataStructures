using System.Diagnostics;


namespace DifferentAddends
{
    public static class DifferentAddends
    {
        public static (int, List<int>) GetDifferentAddendsNumber(this int number)
        {
            Debug.Assert(number >= 1);

            int addendsNumber = 1;
            int addendsSum = 0;
            List<int> addends = new();

            while(addendsSum <= number)
            {
                if (number <= 2)
                {
                    addends.Add(addendsNumber);
                    return (1, addends);
                }

                if (addendsSum + addendsNumber <= number)
                {
                    addends.Add(addendsNumber);
                    addendsSum += addendsNumber;
                    addendsNumber += 1;
                }
                else
                {
                    addendsNumber--;
                    while (addendsSum <= number)
                    {
                        if (number == addendsSum)
                        {
                            return (addendsNumber, addends);
                        }

                        int removedElement = addends.Last();
                        addends.RemoveAt(addends.Count - 1);
                        addends.Add(removedElement + 1);
                        addendsSum += 1;
                    }

                    return (addendsNumber, addends);
                }
            }

            return (addendsNumber, addends);
        }

        public static void Main()
        {
            int number = int.Parse(Console.ReadLine());

            (int addendsNumber, List<int> addends) = number.GetDifferentAddendsNumber();

            Console.WriteLine(addendsNumber);
            addends.ForEach(x => Console.Write("{0} ", x));
        }
    }
}