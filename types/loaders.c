#include "entities.h"

void loaderCategory (Category category) {
    category.addProduct = addProduct;
}

void loaderCategories (Category *categories, int len) {
    for (int index = 0; index < len; index++) {
        categories[index].id = (index + 1);
        categories[index].addProduct = addProduct;
    }
}

void loaderRelations (Relation *relations, int len) {
    for (int index = 0; index < len; index++) {
        relations[index].selectCategory = selectCategory;
    }
}