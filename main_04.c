#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "libs_exercise01.h"

int main() {
    int size_vector = 0, maximun_element = 0, *my_vector_oficial, *my_vector_index, size_index = 0, element;
    int position_index = 0, position_oficial = 0;
   	size_vector = inserting_element();
   	size_index = sqrt(size_vector);
   	maximun_element = inserting_maximun_element();
   	
   	while(maximun_element < size_vector) {
   		maximun_element = inserting_maximun_element();
   	}
    my_vector_oficial = initializing_vector(size_vector, maximun_element);
    
    selection_sort(my_vector_oficial, size_vector);
    print_vector(my_vector_oficial, size_vector);
    my_vector_index = initializing_vector_index(my_vector_oficial, size_vector);

    printf("\nIndice\n");
    print_vector(my_vector_index, size_index);
    printf("Insira o elemento que deseja buscar: ");
    scanf("%d", &element);
    
    position_index = search_element_index(my_vector_index, size_index, element);

    if (presence_in_vector(my_vector_oficial, size_vector, element) == false) {
    	position_index = -1;
    }

    if (presence_in_vector(my_vector_oficial, size_vector, element) == true && 
    	element > *(my_vector_index+(size_index-1))) {
    	position_index = size_index-1;
    }

    position_oficial = indexed_search(my_vector_oficial, my_vector_index, size_vector, position_index, element);
    printf("Posição no vetor de indice: %d\n", position_index);
    printf("Posição no vetor principal: %d\n", position_oficial);

    printf("\n");
    return 0;
}