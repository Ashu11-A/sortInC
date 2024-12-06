#include "algorithms.h"

void combSort(int arr[], int n) {
    int gap = n;
    const float shrink = 1.3;
    int sorted = 0;

    while (gap > 1 || !sorted) {
        gap = (gap > 1) ? (int)(gap / shrink) : 1;
        sorted = 1;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                sorted = 0;
            }
        }
    }
}
