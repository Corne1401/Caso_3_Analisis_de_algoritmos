use std::io;
use std::io::*;
use rand::Rng;

fn main() {
    let mut _a: [u32; 100000] = [0; 100000];
    let mut rng = rand::thread_rng();

    let mut _n = 0;
    let _j = 0;
    let _position = 0;

    println!("Enter number of elements: ");
    
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");

    let trimmed = input_text.trim();
    match trimmed.parse::<u32>() {
        Ok(i) => _n = i,
        Err(..) => println!("this was not an integer: {}", trimmed),
    };

    for index in 0.._n{
        _a[index as usize] = rng.gen::<u32>();
    }

    for element in 0.._n{
        println!("{}",_a[element as usize])
    }
    
}
