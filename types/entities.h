#ifndef ENTITIES_H
#define ENTITIES_H

typedef struct Product Product;
typedef struct Category Category;
typedef struct Relation Relation;

struct Category {
    int id;
    char name[64];

    void (*addProduct)(Product*, Category*, Relation*);
};


struct Product {
    int id;
    char name[64];
    float price;
    int stock;
};

struct Relation {
    int productId;
    int categoryId;

    int (*selectCategory)(Category*, int);
};

void loaderCategories (Category *categories, int len);
void loaderCategory (Category category);

void loaderRelations (Relation *relations, int len);

int selectCategory (Category *categories, int len);
void addProduct(Product* product, Category* category, Relation* relation);

#endif // ENTITIES_H