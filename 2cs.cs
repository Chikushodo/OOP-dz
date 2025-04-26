using System;

public class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Введите количество строк в массиве:");
        int rows = int.Parse(Console.ReadLine());

        Console.WriteLine("Введите количество столбцов в массиве:");
        int cols = int.Parse(Console.ReadLine());

        int[,] array = new int[rows, cols];

        Console.WriteLine("Введите элементы массива построчно:");

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write($"Элемент [{i},{j}]: ");
                array[i, j] = int.Parse(Console.ReadLine());
            }
        }

        Console.WriteLine("\nМассив в обратном порядке (по строкам):");

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                Console.Write(array[i, j] + " ");
            }
            Console.WriteLine(); 
        }
    }
}
