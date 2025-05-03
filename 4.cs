using System;

public class ArrayOperations
{
    public static void RemoveFirstElement(ref int[] array)
    {
        if (array == null || array.Length == 0)
        {
            Console.WriteLine("Массив пуст, нечего удалять.");
            return;
        }

        int[] newArray = new int[array.Length - 1];
        for (int i = 0; i < newArray.Length; i++)
        {
            newArray[i] = array[i + 1]; 
        }

        array = newArray; 
    }
    public static void RemoveLastElement(ref int[] array)
    {
        if (array == null || array.Length == 0)
        {
            Console.WriteLine("Массив пуст, нечего удалять.");
            return;
        }

        int[] newArray = new int[array.Length - 1];
        for (int i = 0; i < newArray.Length; i++)
        {
            newArray[i] = array[i]; 
        }

        array = newArray;
    }
    public static void RemoveElementAtIndex(ref int[] array, int index)
    {
        if (array == null || array.Length == 0)
        {
            Console.WriteLine("Массив пуст, нечего удалять.");
            return;
        }

        if (index < 0 || index >= array.Length)
        {
            Console.WriteLine("Неверный индекс.");
            return;
        }

        int[] newArray = new int[array.Length - 1];
        for (int i = 0, j = 0; i < array.Length; i++)
        {
            if (i == index)
            {
                continue; 
            }
            newArray[j++] = array[i];
        }

        array = newArray; 
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        int[] myArray = { 1, 2, 3, 4, 5 };

        Console.WriteLine("Исходный массив: " + string.Join(", ", myArray));

        ArrayOperations.RemoveFirstElement(ref myArray);
        Console.WriteLine("После удаления первого элемента: " + string.Join(", ", myArray));

        ArrayOperations.RemoveLastElement(ref myArray);
        Console.WriteLine("После удаления последнего элемента: " + string.Join(", ", myArray));

        ArrayOperations.RemoveElementAtIndex(ref myArray, 1);
        Console.WriteLine("После удаления элемента с индексом 1: " + string.Join(", ", myArray));
    }
}
