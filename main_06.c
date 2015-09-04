#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#include "libs_exercise01.h"

int main(){
	int *my_vector, size_my_vector = 0, limits_my_vector, result = 0, element = 0;
	double ti,tf,tempo; // ti = tempo inicial // tf = tempo final


	size_my_vector = inserting_element();
	limits_my_vector = inserting_maximun_element();

	while(limits_my_vector < size_my_vector) {
   		limits_my_vector = inserting_maximun_element();
   	}

	my_vector = initializing_vector(size_my_vector, limits_my_vector);
	selection_sort(my_vector, size_my_vector);
	print_vector(my_vector, size_my_vector);

	printf("Insira o elemento que deseja buscar: ");
    scanf("%d", &element);

/*initializing function for calculate a time of processing*/
  	ti = tf = tempo = 0; 
  	timeval tempo_inicio,tempo_fim; 
	gettimeofday(&tempo_inicio,NULL); 

	result = interpolation_search(my_vector, size_my_vector, 0, element);
	printf("O elemento se encontra aproximadamente na posição %d\n", result);

/*finallilizing function for calculate a time of processing*/
	gettimeofday(&tempo_fim,NULL); 
	tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0)); 
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0)); 
    tempo = (tf - ti) / 1000;
    printf("Tempo gasto em milissegundos %.3f\n",tempo);

	return 0;
}