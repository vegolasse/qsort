#include <iostream>
#include <sys/time.h>


int partition(float *arr, int start, int end) {
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

void dumbqsort(float *arr, int start, int end) {
    if (start >= end) return;

    int index = partition(arr, start, end);

    dumbqsort(arr, start, index);
    dumbqsort(arr, index + 1, end);
}

void dump(float *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    srand((unsigned int) time(NULL));
    int arrLength = 10000000;
    float *arr = new float[arrLength];
    for (int i = 0; i < arrLength; ++i) {
        arr[i] = ((float) rand()) / RAND_MAX;
    }
    //dump(arr, sizeof(arr) / sizeof(float));
    struct timeval start, stop;
    gettimeofday(&start, NULL);

    dumbqsort(arr, 0, arrLength);
    gettimeofday(&stop, NULL);
    double secs = (double) (stop.tv_usec - start.tv_usec) / 1000000 + (double) (stop.tv_sec - start.tv_sec);
    printf("Time: %.1f ms\n", secs * 1000);


    //dump(arr, sizeof(arr) / sizeof(float));


    return 0;
}