#include "utils.h"
#include <stdio.h>
#include <string.h>

void sortProductsByName(Product* products, int quantity) {
    for (int i = 0; i < quantity - 1; i++) {
        for (int j = 0; j < quantity - i - 1; j++) {
            if (strcmp(products[j].name, products[j + 1].name) > 0) {
                // Troca os produtos
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void find(Product* products, int quantity) {
    char name[64];

    printf("Digite o nome do produto: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    // Certifica-se de que os produtos estão ordenados
    sortProductsByName(products, quantity);

    int left = 0, right = quantity - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(products[mid].name, name);

        if (cmp == 0) {
            printf("Nome: %s, Preço: %.2f, Estoque: %d\n",
                products[mid].name, products[mid].price, products[mid].stock);
            return;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Produto não encontrado.\n");
}
