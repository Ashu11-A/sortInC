#include "algorithms.h"
#include <stdio.h>

// Função para partição do QuickSort
int partition(struct Product arr[], int low, int high, int (*cmp)(const void *, const void *)) {
    struct Product pivot = arr[high]; // O pivô é o último elemento
    int i = low - 1; // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (cmp(&arr[j], &pivot) <= 0) {
            i++;    // Incrementa o índice do menor elemento
            struct Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    struct Product temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Função de QuickSort
void quickSort(struct Product arr[], int low, int high, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        // Encontra o índice do pivô
        int pi = partition(arr, low, high, cmp);

        // Ordena recursivamente os subarrays
        quickSort(arr, low, pi - 1, cmp);  // Ordena a parte à esquerda do pivô
        quickSort(arr, pi + 1, high, cmp); // Ordena a parte à direita do pivô
    }
}