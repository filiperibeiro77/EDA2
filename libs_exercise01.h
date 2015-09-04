#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

/* This function initialize the vector with random number receiving one
 size and one number maxminun. In general, the vaues of vectors dont repeating*/

int *initializing_vector(int size_vector, int limits) {
	int i = 0, j = 0, *vector_test;
	vector_test = (int *) malloc(sizeof(int)*size_vector);
		
	srand(time(NULL));
	for (i=0; i < size_vector; i++) {
		*(vector_test + i) = rand() % limits;

		for(j=0; j < i; j++) {
			if(*(vector_test+j) == *(vector_test+i)) {
				*(vector_test+i) = rand() % limits;
				j=0;
			}
		}

	}

	return vector_test;	
}

/*A function is only doing the swap of values when is need*/
void swap_elements(int *num1, int *num2) {
	int auxiliar = 0;

	auxiliar = *num1;
	*num1 = *num2;
	*num2 = auxiliar;
}

/*A function is doing the selection sort for ordenate the values in vector because is
 necessary in the indexed search*/
void selection_sort(int *vector_test, int size_vector) {
	int i = 0, j = 0, auxiliar = 0, smallest_value = 0;
	
	for (i=0; i < size_vector; i++) {
		smallest_value = i;
		for (j=(i+1); j < size_vector; j++)	{
			if (vector_test[smallest_value] > vector_test[j]) {
				smallest_value = j;
			}
		}
		if (smallest_value != i) {
			swap_elements((vector_test+i), (vector_test+smallest_value));
		}
	}
}

/*This fucntion only is testing values. Is used when will initlize vectors for dont type negatives values*/
int test_input_negatives(int value_test) {
	while (value_test <= 0) {
		printf("Valor inválido! Insira novamente um valor maior que zero: ");
		scanf("%d", &value_test);
	}

	return value_test;
}

/*Function used for the insertion of size of vector*/
int inserting_element() {
	int size_vector_test = 0;
	printf("Insira o tamanho que você deseja para o vetor: ");
    scanf("%d", &size_vector_test);

    size_vector_test = test_input_negatives(size_vector_test);

    return size_vector_test;
}

/*Definig the mazimun value possible in the vector*/
int inserting_maximun_element() {
	int maximun_element = 0;
	printf("Insira o maior elemento que você deseja que seja possivel estar no vetor. ");
	printf("Esse valor tem que ser maior que o tamanho do vetor: ");
    scanf("%d", &maximun_element);

    return maximun_element;	
}

void print_vector(int *vector_test, int size_vector_test) {
	int i = 0;
	printf("O vetor gerado é: ");
	for (i=0; i < size_vector_test; i++) {
    	printf("%d   ", *(vector_test+i));
    }

    printf("\n");
}

/*This function initialize the index vector. The size of vector is equal the root of oficial vector's size */
int *initializing_vector_index(int *vector_test, int size_vector_test) {
	int *vector_index, i = 0, size_vector_index = 0, position = 0;
	size_vector_index = sqrt(size_vector_test);
	vector_index = (int *) malloc(sizeof(int)*size_vector_test);

	for (i=0; i < size_vector_test; i++) {
		*(vector_index+i) = *(vector_test+(i*size_vector_index));
	}

	return vector_index;
}

/*This fuction is used for descovery the elements's position in vector oficial.*/
int search_element_vector_oficial(int *vector_test, int size_vector, int value_test) {
	int i = 0;

	for (i=0; i < size_vector; i++) {
		if (*(vector_test+i) == value_test) {
			return i;
		}
	}

	return -1;
}

bool presence_in_vector (int *vector_test, int size_vector, int value_test) {
	if (search_element_vector_oficial(vector_test, size_vector, value_test) == -1) {
		return false;
	}

	else {
		return true;
	}
}

/*This fuction is used for descovery the elements's position in vector index.*/
int search_element_index(int *vector_test, int size_vector, int value_test) {
	int i = 0, position;

	for (i=0; i < size_vector; i++) {
		if (*(vector_test+i) > value_test) {
			return i-1;
		}

		else if (*(vector_test+i) == value_test) {
			return i;
		}
	}

	return -1;
}

/*indexed search feito with the position of value correspondent in the index's vector*/
int indexed_search(int *vector_oficial_test, int *vector_index_test, int size_vector, int position_index_test, int value_test) {
	int i = 0;
	int inferior_limit = *(vector_index_test+(position_index_test));
	int superior_limit = (position_index_test+1)*(sqrt(size_vector));
	int index_oficial;
	index_oficial = position_index_test*(sqrt(size_vector));

	for (i = index_oficial; i <= superior_limit; i++){		
		printf("Elementos percorridos %d\n", *(vector_oficial_test+i));
		if (value_test == *(vector_oficial_test+i)) {
			return i;
		}
	}
	return -1;
}

/*Interpolation method search. only is necessary change values in a formula and magically the approximate
 value of position is returned*/
int interpolation_search(int *vector_test, int size_vector, int smallest_positon, int value_test){
	int medium = 0;
	int sup = 0;
	sup = size_vector -1;

	if (search_element_vector_oficial(vector_test, size_vector, value_test) == -1) {
		return -1;
	}

	else {
		medium = smallest_positon + (sup - smallest_positon)*(value_test - vector_test[0] )/(vector_test[sup] - vector_test[0]);
		return medium;
	}
}

int binary_search(int *vector_test, int size_vector, int key_search) {
	int medium = 0;
	int limit_inf = 0;
	int limit_sup = size_vector - 1;

	medium = size_vector/2;
	
	while (limit_inf <= limit_sup) {
		medium = (limit_sup + limit_inf)/2;
		if(key_search == *(vector_test+medium)) {
			return medium;
		}

		else if (key_search == *(vector_test+medium)) {
			limit_sup = medium - 1;
		}

		else {
			limit_inf = medium + 1;
		}
	}
	return -1;
}