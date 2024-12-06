#include "algorithms.h"
#include <string.h>

// Função de comparação para ordenar por nome (A-Z)
int compareByName(const void *a, const void *b) {
    struct Product *prodA = (struct Product *)a;
    struct Product *prodB = (struct Product *)b;
    return strcmp(prodA->name, prodB->name);
}

// Função de comparação para ordenar por preço
int compareByPrice(const void *a, const void *b) {
    struct Product *prodA = (struct Product *)a;
    struct Product *prodB = (struct Product *)b;
    if (prodA->price < prodB->price) return -1;
    if (prodA->price > prodB->price) return 1;
    return 0;
}

// Função de comparação para ordenar por id
int compareById(const void *a, const void *b) {
    struct Product *prodA = (struct Product *)a;
    struct Product *prodB = (struct Product *)b;
    return prodA->id - prodB->id;
}

// Função de comparação para ordenar por Estoque
int compareByStock(const void *a, const void *b) {
    struct Product *prodA = (struct Product *)a;
    struct Product *prodB = (struct Product *)b;
    return prodA->stock - prodB->stock;
}

