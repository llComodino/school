#![allow(unused)]
use std::io::{Read,Write};
use std::net::{TcpListener, TcpStream};
use http_request_parser::{Request, Response};

fn main() {
    
    let mut stream = TcpStream::connect("127.0.0.1:8080").unwrap();
    
    let request = "GET / HTTP/1.1\r\nHost: localhost:8080\r\n\r\n";
    
    let mut buffer = [0; 256];
    let mut response = Response::new();

    stream.write(request.as_bytes()).unwrap();
    stream.read(&mut buffer).unwrap();

    response.body = String::from_utf8_lossy(&buffer).to_string();

    println!("Response: {:?}", response);

}
