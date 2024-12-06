#include "algorithms.h"

void stoogeSort(int arr[], int l, int h) {
    if (l >= h) return;

    if (arr[l] > arr[h]) {
        int temp = arr[l];
        arr[l] = arr[h];
        arr[h] = temp;
    }

    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;

        stoogeSort(arr, l, h - t);
        stoogeSort(arr, l + t, h);
        stoogeSort(arr, l, h - t);
    }
}
