#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void genProducts(Product *products, Relation *relations, int* registered, int lenCategories, int maxProdutos) {
    if (*registered >= maxProdutos) {
        printf("Não é possível adicionar mais produtos. Limite atingido.\n");
        return;
    }

    int qtdGerar;
    printf("Digite a quantidade de produtos a serem gerados: ");
    scanf("%d", &qtdGerar);

    if (qtdGerar <= 0 || *registered + qtdGerar > maxProdutos) {
        printf("Quantidade inválida ou excede o limite máximo de produtos.\n");
        return;
    }

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for (int i = 0; i < qtdGerar; i++) {
        printf("%d", *registered);
        // Gerar um nome aleatório de produto
        char nomeProduto[64];
        snprintf(nomeProduto, sizeof(nomeProduto), "Produto %c%c%c%c%c", 
                 'A' + rand() % 26, 
                 'A' + rand() % 26, 
                 'A' + rand() % 26, 
                 'A' + rand() % 26, 
                 'A' + rand() % 26);
        
        // Gerar categoria aleatória
        int indexCategory = rand() % lenCategories;

        // Gerar preço aleatório entre 0.00 e 99.99
        float precoAleatorio = (rand() % 100);

        // Gerar estoque aleatório entre 0 e 99
        int estoqueAleatorio = rand() % 100;

        relations[*registered].productId = *registered;
        relations[*registered].categoryId = indexCategory;
    
        // Atribuir valores ao produto
        strcpy(products[*registered].name, nomeProduto);
        products[*registered].id = *registered;
        products[*registered].price = precoAleatorio;
        products[*registered].stock = estoqueAleatorio;

        // Exibir produto gerado
        printf("Produto gerado: %s | Preço: %.2f | Estoque: %d\n", 
               products[*registered].name, 
               //products[*quantidade].categoria, 
               products[*registered].price, 
               products[*registered].stock
            );

        // Incrementar a quantidade de produtos gerados
        (*registered)++;
    }

    printf("%d produtos gerados aleatoriamente com sucesso!\n", qtdGerar);
}