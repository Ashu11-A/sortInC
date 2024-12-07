<div align="center">

# SortInC

![SourceForge Languages](https://img.shields.io/github/languages/top/Ashu11-A/sortInC?style=for-the-badge&colorA=302D41&colorB=90dceb)

![license-info](https://img.shields.io/github/license/Ashu11-A/sortInC?style=for-the-badge&colorA=302D41&colorB=f9e2af&logoColor=f9e2af)
![stars-info](https://img.shields.io/github/stars/Ashu11-A/sortInC?colorA=302D41&colorB=f9e2af&style=for-the-badge)
![reposize-info](https://img.shields.io/github/languages/code-size/Ashu11-A/sortInC?style=for-the-badge&colorA=302D41&colorB=90dceb)


</div>

## 📚 Sobre o Projeto

Este repositório é resultado da conclusão da disciplina **Algoritmos e Lógica de Programação**, ministrada pela professora **Lorena Borges**. 🎓

O projeto foi desenvolvido para explorar a implementação prática de **algoritmos de ordenação (sort algorithms)** em **C**, e integrar conceitos de **gestão de memória dinâmica**, **estruturas de dados**, e **modularização de código**.

---

## 🚀 Funcionalidades Implementadas

### 📦 Gerenciamento de Produtos
- **Criação de produtos com `structs`:**  
  - Produtos são representados por uma estrutura com atributos como `id`, `name`, `price` e `stock`.  
  - Atribuição dinâmica de produtos a categorias é gerenciada via **relações**.

### 🔄 Algoritmos de Ordenação
- **Bubble Sort** e **Quick Sort** foram implementados para ordenar produtos.
- O usuário pode alternar entre os algoritmos e avaliar a diferença de desempenho.
- Ordenação genérica permite filtrar por nome ou preço, utilizando ponteiros para funções de comparação.

### ⚙️ Funções Adicionais
1. **Filtros personalizados:**  
   Produtos podem ser filtrados por categoria e exibidos de forma ordenada.
2. **Busca e reposição:**  
   Identificação de produtos abaixo do estoque mínimo.
3. **Gerador de dados aleatórios:**  
   Geração automatizada de produtos para testar algoritmos em grande escala.
4. **Menu Interativo:**  
   Operações acessíveis via um menu claro e funcional.

---

## 📋 Estrutura do Código

### 🔧 Principais Componentes

#### Estruturas de Dados
1. **`struct Product`:**  
   Representa os produtos do sistema:
   ```c
   struct Product {
       int id;
       char name[64];
       float price;
       int stock;
   };
   ```
2. **`struct Category`:**  
   Representa categorias de produtos, com função de adição personalizada:
   ```c
   struct Category {
       int id;
       char name[64];
       void (*addProduct)(Product*, Category*, Relation*);
   };
   ```
3. **`struct Relation`:**  
   Relaciona produtos às suas respectivas categorias:
   ```c
   struct Relation {
       int productId;
       int categoryId;
       int (*selectCategory)(Category*, int);
   };
   ```

#### Modularização
- **`entities.h`:** Contém a definição das estruturas e funções relacionadas a produtos, categorias e relações.
- **`algorithms.h`:** Implementa os algoritmos de ordenação.
- **`utils.h`:** Inclui funções auxiliares, como geração de dados e comparação.

---

## 🛠 Técnicas Utilizadas

- **Alocação Dinâmica de Memória:**  
  Uso extensivo de `malloc` e `free` para escalabilidade.
- **Modularização:**  
  Código organizado em arquivos separados para clareza e reusabilidade.
- **Funções Genéricas:**  
  Integração de funções para comparação dinâmica durante a ordenação.
- **Uso de Ponteiros para Funções:**  
  Permite implementar comportamentos customizados para ordenação e filtragem.

---

## 🎯 Objetivos do Projeto

1. **Explorar algoritmos de ordenação:**  
   Estudo detalhado do comportamento e da eficiência de algoritmos.
2. **Aprimorar gestão de memória:**  
   Manipulação eficiente de grandes volumes de dados em memória.
3. **Desenvolver uma aplicação interativa e prática:**  
   Fornecer uma interface clara para explorar os conceitos implementados.

---

## 📦 Tecnologias Utilizadas

- Linguagem **C**.
- Estruturas de dados e modularização.
- Alocação dinâmica de memória com **`malloc`**.
- Análise de desempenho usando medições de tempo de execução.

---

## 📝 Licença

Este projeto está sob a licença [GPL-3.0](./LICENSE).

---
