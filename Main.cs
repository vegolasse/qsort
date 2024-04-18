using System;
using System.Diagnostics;
using System.Linq;

public class Program
{
    public static int Partition(float[] arr, int start, int end)
    {
        int cursor = start;
        float pivot = arr[end - 1];
        for (int i = start; i < end - 1; i++)
        {
            if (arr[i] <= pivot)
            {
                float temp = arr[cursor];
                arr[cursor] = arr[i];
                arr[i] = temp;
                cursor++;
            }
        }

        float temp2 = arr[cursor];
        arr[cursor] = arr[end - 1];
        arr[end - 1] = temp2;
        return cursor;
    }

    public static void DumbQSort(float[] arr, int start, int end)
    {
        if (start >= end) return;

        int index = Partition(arr, start, end);

        DumbQSort(arr, start, index);
        DumbQSort(arr, index + 1, end);
    }

    public static void Dump(float[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write($"{arr[i]:F4} ");
        }
        Console.WriteLine();
    }

    public static void Main(string[] args)
    {
        Random rand = new Random();
        int arrLength = 100000000;
        float[] arr = Enumerable.Range(0, arrLength).Select(i => (float)rand.NextDouble()).ToArray();

        // Dump(arr);

        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();

        DumbQSort(arr, 0, arrLength);

        stopwatch.Stop();
        double secs = stopwatch.Elapsed.TotalMilliseconds / 1000.0;
        Console.WriteLine($"Time: {secs:F1} ms");

        // Dump(arr);
    }
}