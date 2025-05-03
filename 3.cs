using System;

public class Program
{
    public static void Main(string[] args)
    {
        string[] productNames = { "Яблоко", "Банан", "Апельсин", "Манго" };
        double[] productPrices = { 15.5, 25.0, 30.75, 70.0 };

        if (productNames.Length != productPrices.Length)
        {
            Console.WriteLine("Ошибка: Количество названий и цен товаров не совпадает!");
            return; 
        }

        double averagePrice = CalculateAverage(productPrices);

        Console.WriteLine("Средняя цена товаров: " + averagePrice);
        Console.WriteLine("\nСписок товаров и цен:");

        for (int i = 0; i < productNames.Length; i++)
        {
            Console.WriteLine(productNames[i] + ": " + productPrices[i] + " руб.");
        }
    }
    static double CalculateAverage(params double[] prices)
    {
        if (prices == null || prices.Length == 0)
        {
            return 0; 
        }

        double sum = 0;
        foreach (double price in prices)
        {
            sum += price;
        }

        return sum / prices.Length;
    }
}
