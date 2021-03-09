#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int n = 100;		//numero de elementos de array
	int smallest;	//posicion en la que queda el mas pequeno del array
	int swap;		//para almacenar el numero que se va a intercambiar
	clock_t t;
	int a[100];		//array donde se guardan los numeros

int main() {
	/*
	int n = 20000;		//numero de elementos de array
	int smallest;	//posicion en la que queda el mas pequeno del array
	int swap;		//para almacenar el numero que se va a intercambiar
	clock_t t;
	int a[n];		//array donde se guardan los numeros
	*/

	srand(time(NULL));
	for(int i = 0; i < n; i++) {		//crea el array de n elementos aleatorios
		a[i] = ( rand() % 100 );		//rango de 0 a 99
	}

	t = clock();
	
	for(int i = 0; i < n-1; i++) {
		smallest = i;
		for(int j = i+1; j < n; j++) {	//busca el numero mas pequeno del array
			if(a[smallest] > a[j])
				smallest = j;
		}
		if(smallest != i) { 		//revisa si hay que hacer swap para dejar el mas pequeno mas a la izquierda
			swap = a[i];
			a[i] = a[smallest];
			a[smallest] = swap;
		}
	}
	
	//printf("Sorted Array:\n");		//imprime el array ya ordenado
	//for(int i = 0; i < n; i++)
		//printf("%d  ", a[i]);

	printf("\n");
	t = clock() - t;
	printf ("Execution time: %f s\n", ((float)t)/CLOCKS_PER_SEC);


	printf ("Used Memory: %d \n", &(a[n-1]) - &n );
	
	return 0;
}
