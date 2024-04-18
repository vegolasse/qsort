#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

int partition(std::vector<float>& arr, int start, int end) {
    int cursor = start;
    float pivot = arr.at(end - 1);
    for (int i = start; i < end - 1; i++) {
        if (arr.at(i) <= pivot) {
            float temp = arr.at(cursor);
            arr.at(cursor) = arr.at(i);
            arr.at(i) = temp;
            cursor++;
        }
    }

    float temp = arr.at(cursor);
    arr.at(cursor) = arr.at(end - 1);
    arr.at(end - 1) = temp;
    return cursor;
}

void dumbqsort(std::vector<float>& arr, int start, int end) {
    if (start >= end) return;

    int index = partition(arr, start, end);

    dumbqsort(arr, start, index);
    dumbqsort(arr, index + 1, end);
}

void dump(const std::vector<float>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%.4f ", arr.at(i));
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    int arrLength = 100000000;
    std::vector<float> arr(arrLength);
    for (int i = 0; i < arrLength; ++i) {
        arr.at(i) = static_cast<float>(rand()) / RAND_MAX;
    }
    // dump(arr);
    struct timeval start, stop;
    gettimeofday(&start, NULL);

    dumbqsort(arr, 0, arrLength);

    gettimeofday(&stop, NULL);
    double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("Time: %.1f ms\n", secs * 1000);

    // dump(arr);

    return 0;
}