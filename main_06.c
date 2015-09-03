#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "libs_exercise01.h"

int main(){
	int *my_vector, size_my_vector = 0, limits_my_vector, result = 0, element = 0;

	size_my_vector = inserting_element();
	limits_my_vector = inserting_maximun_element();
	my_vector = initializing_vector(size_my_vector, limits_my_vector);
	selection_sort(my_vector, size_my_vector);
	print_vector(my_vector, size_my_vector);

	printf("Insira o elemento que deseja buscar: ");
    scanf("%d", &element);

	result = interpolation_search(my_vector, size_my_vector, element);
	printf("O elemento se encontra na posição %d\n", result);
	return 0;
}