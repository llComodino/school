use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};

fn handle_client(mut stream: TcpStream) {
    
    let mut buffer = [0; 512];
    
    stream.read(&mut buffer).expect("Error reading stream");

    let request = String::from_utf8_lossy(&buffer[..]);
    println!("Request: {}", request);

    
    let response = "HTTP/1.1 200 OK\r\n\r\nHello, world!";
    stream.write(response.as_bytes()).expect("Error writing response");
}

fn main() {
    
    let listener = TcpListener::bind("127.0.0.1:8080").expect("Error binding to port 8080");
    println!("Listening on port 8080");
    
    for stream in listener.incoming() {
        match stream {
            Ok(stream) => {
                std::thread::spawn(|| handle_client(stream));
            }
            Err(e) => {
                eprintln!("Error: {}", e);
            }
        }
    }
}
