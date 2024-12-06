#include "./algorithms/algorithms.h"
#include "./types/entities.h"
#include "./utils/utils.h"
#include<stdio.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxProducts = 100000;

void sortProducts(SortAlgorithm algorithm, struct Product products[], int n, int (*cmp)(const void *, const void *));
int filterProductsByCategory(struct Product *filteredProducts, struct Product *products, struct Relation *relations, int categoryId, int quantity);

struct Product *products;
struct Relation *relations;
SortAlgorithm selectedAlgorithm = QUICK_SORT;

int main() {
    int option;
    int quantity = 0;

    Category categories[2] = {
        {0, "Notebooks"},
        {0, "Smartphones"},
    };
    products = (struct Product *)malloc(maxProducts * sizeof(struct Product));
    relations = (struct Relation *)malloc(maxProducts * sizeof(struct Relation));

    int categoriesLen = sizeof(categories) / sizeof(categories[0]);
    int relationsLen = sizeof(relations) / sizeof(relations[0]);
    loaderCategories(categories, categoriesLen);
    loaderRelations(relations, relationsLen);

        do {
    printf("\n\033[1;33m--- Menu ---\033[0m\n");
    printf("\033[36m1. Cadastrar produto\033[0m\n");
    printf("\033[36m2. Exibir produtos cadastrados\033[0m\n");
    printf("\033[36m3. Exibir produtos por categoria (faz a ordenação por nome)\033[0m\n");
    printf("\033[36m4. Exibir produtos por categoria (faz a ordenação por preço)\033[0m\n");
    printf("\033[36m5. Verificar necessidade de reposição\033[0m\n");
    printf("\033[36m6. Buscar produto por nome\033[0m\n");
    printf("\033[34m7. Gerar produtos aleatórios\033[0m\n");
    printf("\033[35m8. Selecionar algoritmo\033[0m\n");
    printf("\033[35m9. Procurar melhor algoritmo\033[0m\n");
    printf("\033[31m10. Sair\033[0m\n");
    printf("\033[42mEscolha uma opção:\033[0m ");
    scanf("%d", &option);

        clock_t start, end;
        double elapsed;

        switch (option) {
        case 1:
    
            int categoryId = selectCategory(categories, categoriesLen);
            categories[categoryId].addProduct(&products[quantity], &categories[categoryId], &relations[quantity]);

            quantity++;
            break;
        case 2:
            start = clock();

            for (int index = 0; index < quantity; index++) {
                int productId = relations[index].productId;
                int categoryId = relations[index].categoryId;

                Category category = categories[categoryId];
                Product product = products[productId];

                printf("Id: %d | Produto: %s | Preço: %.2f | Estoque: %d | Categoria: %s\n",
                    product.id,
                    product.name,
                    product.price,
                    product.stock,
                    category.name
                );
            }

            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        case 3: {
            start = clock();

            printf("Selecione a categoria para exibir produtos ordenados por nome:\n");
            for (int i = 0; i < categoriesLen; i++) {
                printf("%d. %s\n", i, categories[i].name);
            }

            int categoryId;
            printf("Digite o ID da categoria: ");
            scanf("%d", &categoryId);

            if (categoryId < 0 || categoryId >= categoriesLen) {
                printf("Categoria inválida!\n");
                break;
            }

            // Filtrar os produtos por categoria
            struct Product *filteredProducts = (struct Product *)malloc(quantity * sizeof(struct Product));
            int filteredCount = filterProductsByCategory(filteredProducts, products, relations, categoryId, quantity);

            // Ordenar os produtos filtrados por nome
            sortProducts(selectedAlgorithm, filteredProducts, filteredCount, compareByName);

            // Exibir os produtos filtrados e ordenados
            printf("Produtos da categoria '%s' ordenados por nome:\n", categories[categoryId].name);
            for (int i = 0; i < filteredCount; i++) {
                printf("Id: %d | Produto: %s | Preço: %.2f | Estoque: %d\n",
                    filteredProducts[i].id,
                    filteredProducts[i].name,
                    filteredProducts[i].price,
                    filteredProducts[i].stock);
            }

            free(filteredProducts);

            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        }

        case 4: {
            start = clock();

            printf("Selecione a categoria para exibir produtos ordenados por preço:\n");
            for (int i = 0; i < categoriesLen; i++) {
                printf("%d. %s\n", i, categories[i].name);
            }

            int categoryId;
            printf("Digite o ID da categoria: ");
            scanf("%d", &categoryId);

            if (categoryId < 0 || categoryId >= categoriesLen) {
                printf("Categoria inválida!\n");
                break;
            }

            // Filtrar os produtos por categoria
            struct Product *filteredProducts = (struct Product *)malloc(quantity * sizeof(struct Product));
            int filteredCount = filterProductsByCategory(filteredProducts, products, relations, categoryId, quantity);

            // Ordenar os produtos filtrados por preço
            sortProducts(selectedAlgorithm, filteredProducts, filteredCount, compareByPrice);

            // Exibir os produtos filtrados e ordenados
            printf("Produtos da categoria '%s' ordenados por preço:\n", categories[categoryId].name);
            for (int i = 0; i < filteredCount; i++) {
                printf("Id: %d | Produto: %s | Preço: %.2f | Estoque: %d\n",
                    filteredProducts[i].id,
                    filteredProducts[i].name,
                    filteredProducts[i].price,
                    filteredProducts[i].stock);
            }

            free(filteredProducts);

            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        }
        case 5: {
            printf("Limite mínimo de estoque: ");
            int minStock;
            scanf("%d", &minStock);

            printf("\nProdutos que estão abaixo do limite minimo:\n");

            int needsRestock = 0; // Contador para produtos abaixo do limite
            for (int i = 0; i < quantity; i++) {
                if (products[i].stock < minStock) {
                    int productId = relations[i].productId;
                    int categoryId = relations[i].categoryId;

                    Category category = categories[categoryId];
                    Product product = products[productId];

                    printf("Id: %d | Produto: %s | Estoque: %d | Categoria: %s\n",
                        product.id, product.name, product.stock, category.name);

                    needsRestock++;
                }
            }

            if (needsRestock == 0) {
                printf("Todos os produtos estão com estoque suficiente.\n");
            }
            break;
        }
        case 6:
            start = clock();

            find(products, quantity);

            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        case 7:
            start = clock();

            genProducts(products, relations, &quantity, categoriesLen, maxProducts);

            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        case 8: {
            start = clock();

            printf("Selecione o algoritmo de ordenação:\n");
            printf("1. Bubble Sort\n");
            printf("2. Quick Sort\n");
            int algoOption;
            scanf("%d", &algoOption);

            switch (algoOption) {
                case 1:
                    selectedAlgorithm = BUBBLE_SORT;
                    printf("Algoritmo selecionado: Bubble Sort\n");
                    break;
                case 2:
                    selectedAlgorithm = QUICK_SORT;
                    printf("Algoritmo selecionado: Quick Sort\n");
                    break;
                default:
                    printf("Opção inválida! Mantendo o algoritmo atual.\n");
                    break;
            }
            
            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
            break;
        }
        case 9:
            break;
        
        default:
            printf("\033[41mOpção inexistente!\033[0m\n");
            break;
        }

        printf("\033[32mTempo para processar a request: %.5f segundos\033[0m\n", elapsed);
    } while (option != 10);

    free(products);
    free(relations);

    return 0;
}


void sortProducts(SortAlgorithm algorithm, struct Product products[], int n, int (*cmp)(const void *, const void *)) {
    switch (algorithm) {
        case BUBBLE_SORT:
            bubbleSort(products, n, cmp);
            break;
        case QUICK_SORT:
            quickSort(products, 0, n - 1, cmp);
            break;
        default:
            printf("Algoritmo de ordenação não implementado!\n");
            break;
    }
}

int filterProductsByCategory(struct Product *filteredProducts, struct Product *products, struct Relation *relations, int categoryId, int quantity) {
    int count = 0;

    for (int i = 0; i < quantity; i++) {
        if (relations[i].categoryId == categoryId) {
            filteredProducts[count++] = products[relations[i].productId];
        }
    }

    return count; // Retorna o número de produtos filtrados
}