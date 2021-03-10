package main

import (
	"fmt"
	"math/rand"
	"time"
)

const n int = 200000	//numero de elementos de array
	var a[n]int			//array donde se guardan los numeros
	var smallest int	//posicion en la que queda el mas pequeno del array
	var swap int		//para almacenar el numero que se va a intercambiar

func main() {

	/*
	const n = 10		//numero de elementos de array
	var a[n]int			//array donde se guardan los numeros
	var smallest int	//posicion en la que queda el mas pequeno del array
	var swap int		//para almacenar el numero que se va a intercambiar
*/

	rand.Seed(time.Now().UnixNano())	//obtiene y setea una semilla diferente para que los numeros sean diferentes con cada corrida del programa
	for i := 0; i < n; i++ {		//crea el array de n elementos aleatorios
		a[i] = rand.Intn(100)		//rango de 0 a 99
	}
	//fmt.Println("Unsorted Array:")		//imprime el array desordenado
	//fmt.Println(a)
	
	fmt.Println("\n")
	startTime := time.Now()
	//fmt.Printf("Memory: %v", &smallest )
	

	for i := 0; i < n-1; i++ {
		smallest = i
		for j := i+1; j < n; j++ {	//busca el numero mas pequeno del array
			if a[smallest] > a[j] {
				smallest = j
			}				
		}
		if smallest != i { 		//revisa si hay que hacer swap para dejar el m�s peque�o m�s a la izquierda
			swap = a[i]
			a[i] = a[smallest]
			a[smallest] = swap
		}
	}

	//fmt.Println("Sorted Array:")		//imprime el array ya ordenado
	//fmt.Println(a)

	endTime := time.Now()
	fmt.Println("")
	//fmt.Printf("Memory: %v", &(a[n-1])  )

	totalTime := endTime.Sub(startTime)
	fmt.Println("\n")
	fmt.Println("Execution time: ")
	fmt.Println(totalTime)
	fmt.Println("\n")

}