#include <stdio.h>
#include "entities.h"

int findCategoryById(Category *categories, int len, int categoryId) {
    for (int i = 0; i < len; i++) {
        if (categories[i].id == categoryId) {
            return i; // Retorna o índice da categoria
        }
    }
    return -1; // Retorna -1 se não encontrar
}

int selectCategory (Category *categories, int len) {
    int categoryId;
    int index;

    do {
        printf("Categorias disponíveis:\n");

        for (int i = 0; i < len; i++) {
            printf("Id: %d, Nome: %s\n", categories[i].id, categories[i].name);
        }

        printf("\nSelecione o ID da Categoria que deseja adicionar um produto: ");
        scanf("%d", &categoryId);
        getchar();

        index = findCategoryById(categories, len, categoryId);

        if (index == -1) {
            printf("Categoria não encontrada. Tente novamente.\n");
        }
    } while (index == -1);

    return index;
}

