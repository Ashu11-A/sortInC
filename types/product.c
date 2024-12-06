#include <stdio.h>
#include "entities.h"

/*
 * Parecido com OO (Orientação a Objetos)
 */
void addProduct(Product* product, Category* category, Relation* relation) {
    printf("Nome do produto: ");
    getchar();
    fgets(product->name, sizeof(product->name), stdin);

    printf("Preço: ");
    scanf("%f", &product->price);

    printf("Quantidade em estoque: ");
    scanf("%d", &product->stock); 
    getchar();

    relation->productId = product->id;
    relation->categoryId = category->id;
}
