import java.util.Random;

public class Main {
    public static int partition(float[] arr, int start, int end) {
        int cursor = start;
        float pivot = arr[end - 1];
        for (int i = start; i < end - 1; i++) {
            if (arr[i] <= pivot) {
                float temp = arr[cursor];
                arr[cursor] = arr[i];
                arr[i] = temp;
                cursor++;
            }
        }

        float temp = arr[cursor];
        arr[cursor] = arr[end - 1];
        arr[end - 1] = temp;
        return cursor;
    }

    public static void dumbqsort(float[] arr, int start, int end) {
        if (start >= end) return;

        int index = partition(arr, start, end);

        dumbqsort(arr, start, index);
        dumbqsort(arr, index + 1, end);
    }

    public static void dump(float[] arr, int len) {
        for (int i = 0; i < len; i++) {
            System.out.printf("%.4f ", arr[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int arrLength = 100000000;
        float[] arr = new float[arrLength];
        for (int i = 0; i < arrLength; ++i) {
            arr[i] = rand.nextFloat();
        }

        // dump(arr, arr.length);

        long startTime = System.currentTimeMillis();

        dumbqsort(arr, 0, arrLength);

        long stopTime = System.currentTimeMillis();
        double secs = (stopTime - startTime) / 1000.0;
        System.out.printf("Time: %.1f ms\n", secs * 1000);

        // dump(arr, arr.length);
    }
}