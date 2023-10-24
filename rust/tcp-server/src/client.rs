use std::io::{Read,Write};
use std::net::{TcpListener, TcpStream};

fn main() {
    
    let mut stream = TcpStream::connect("127.0.0.1:8080").unwrap();
    stream.write(b"Hello World").unwrap();
    
    let mut response = String::new();
    stream.read_to_string(&mut response).unwrap();
    
    println!("{}", response);
}
