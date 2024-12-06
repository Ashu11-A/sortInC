#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include "../types/entities.h"

typedef enum {
    BUBBLE_SORT,
    QUICK_SORT
} SortAlgorithm;

void bubbleSort(struct Product arr[], int n, int (*cmp)(const void *, const void *));
void quickSort(struct Product arr[], int low, int high, int (*cmp)(const void *, const void *));

// Declaração das funções
void combSort(int arr[], int n);
void gnomeSort(int arr[], int n);
void heapSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void radixSort(int arr[], int n);
void selectionSort(int arr[], int n);
void stoogeSort(int arr[], int l, int h);

int compareByPrice(const void *a, const void *b);
int compareById(const void *a, const void *b);
int compareByName(const void *a, const void *b);
int compareByStock(const void *a, const void *b);

#endif // SORT_ALGORITHMS_H
