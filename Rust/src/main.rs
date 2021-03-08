use std::io;
use std::io::*;
use rand::Rng;
use std::time::{Duration, Instant};

fn main() {
    let mut rng = rand::thread_rng();

    let mut _n = 0;
    let mut position;
    let mut swap;

    //input para definir el tamaño del array
    println!("ingrese numero de elementos(200000 max): "); 
    let mut input_text = String::new();
    io::stdin().read_line(&mut input_text).expect("failed to read from stdin");

    //conversion del string del input a un numero entero
    let trimmed = input_text.trim();
    match trimmed.parse::<u32>() {
        Ok(i) => _n = i,
        Err(..) => println!("this was not an integer: {}", trimmed),
    };

    let mut _a = vec![0;_n as usize];

    //se llena el array con numeros random
    for index in 0.._n{
        _a[index as usize] = rng.gen::<u32>();
    }

    let start = Instant::now();

    for i in 0.._n+1{
    
        position = i;
        //busca element mas pequeño del array
        for j in i+1.._n{
            if _a[position as usize] > _a[j as usize]{
                position = j;
            }
        }
        //revisa si hay que hacer un swap
        if position != i{
            swap = _a[i as usize];
            _a[i as usize] = _a[position as usize];
            _a[position as usize] = swap;
            
        }

    }

    let duration = start.elapsed();

    println!("El tiempo de ejecucion fue de: {:?}", duration);

    //imprime el array ordenado
    //for x in 0.._n{ println!("{}",_a[x as usize]); }
    

}
