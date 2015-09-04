#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "libs_exercise01.h"

typedef struct TNode{
	int value;
	struct TNode *next_node;
}TNode;

typedef struct TList{
    int quantity_elements;
    struct TNode *head;
    struct TNode *tail;
}TList;

TList *include_head(TList *test_list, int value_test) {
    TNode *new_node;
    new_node = (TNode* ) malloc(sizeof(TNode));
    new_node->value = value_test;

    if(test_list->head == NULL) {
        test_list->head = test_list->tail = new_node;
        test_list->tail->next_node = test_list->head;
    }

    else {
        new_node->next_node = test_list->head;
        test_list->head = new_node;
    }

    test_list->quantity_elements++;

    return test_list;
}

int *initializing_vector(TList *test_list) {
    int i = 0;
    int *vector;
    vector = (int *) malloc(sizeof(int)*test_list->quantity_elements);

    TNode *auxiliar_list;
    auxiliar_list = test_list->head;

    for (i = 0; i < test_list->quantity_elements; i++) {
        vector[i] = auxiliar_list->value;
        auxiliar_list = auxiliar_list->next_node;
    }

    return vector;
}

void print_list(TList *test_list) {
    int i = 0;
    int vector[test_list->quantity_elements];

    TNode *auxiliar_list;
    auxiliar_list = test_list->head;

    if(test_list->head == NULL) {
        printf("Lista vazia!\n");
    }

    else {
        for (i = 0; i < test_list->quantity_elements; i++) {
            printf("%d   ", auxiliar_list->value);
            vector[i] = auxiliar_list->value;
            auxiliar_list = auxiliar_list->next_node;
        }
    }
}


int main(){
    TList *my_list, one_list;
    my_list = &one_list;
    my_list->head = my_list->tail = NULL;
    my_list->quantity_elements = 0;
    int my_value = 0, *vector, i = 0, position = 0;
    char option;

    do{
        printf("1 - Incluir elemento: \n");
        printf("2 - Imprimir lista: \n");
        printf("3 - Buscar posição de um elemento: \n");
        printf("0 - Sair: ");
        scanf("%1s", &option);

        if (option == '1'){
            printf("Digite o valor que voce deseja inserir na lista: ");
            scanf("%d", &my_value);
            my_list = include_head(my_list, my_value);
        }

        if (option == '2'){
            print_list(my_list);
            vector = initializing_vector(my_list);
            selection_sort(vector, my_list->quantity_elements);
            printf("\n");
            print_vector(vector, my_list->quantity_elements);
        }

        if (option == '3') {
            vector = initializing_vector(my_list);
            selection_sort(vector, my_list->quantity_elements);
            printf("Digite o elemento que voce deseja buscar na lista: ");
            scanf("%d", &my_value);
            position = binary_search(vector, my_list->quantity_elements, my_value);
            printf("O elemento se encontra na posição %d\n", position);
        }

        printf("\n");
    }while(option != '0');

    return 0;
}