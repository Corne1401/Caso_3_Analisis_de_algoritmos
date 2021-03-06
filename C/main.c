#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
	int n = 100000;		//numero de elementos de array
	int a[n];		//array donde se guardan los numeros
	int smallest;	//posicion en la que queda el más pequeño del array
	int swap;		//para almacenar el numero que se va a intercambiar
	
	srand(time(NULL));
	for(int i = 0; i < n; i++) {		//crea el array de n elementos aleatorios
		a[i] = ( rand() % 100 );		//rango de 0 a 99
	}
			
	for(int i = 0; i < n-1; i++) {
		smallest = i;
		for(int j = i+1; j < n; j++) {	//busca el numero más pequeño del array
			if(a[smallest] > a[j])
				smallest = j;
		}
		if(smallest != i) { 		//revisa si hay que hacer swap para dejar el más pequeño más a la izquierda
			swap = a[i];
			a[i] = a[smallest];
			a[smallest] = swap;
		}
	}
	
	printf("Sorted Array:\n");		//imprime el array ya ordenado
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	
	
	
	return 0;
}
