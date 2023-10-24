// Client for the IRC

use std::net::TcpStream;


pub struct Client {
    pub stream: TcpStream,
    pub nick: String,
    pub user: String,
    pub real_name: String,
    pub channel: String,
}

impl Client {
    pub fn new (stream: TcpStream) -> Client {
        Client {
            stream: stream,
            nick: String::new(),
            user: String::new(),
            real_name: String::new(),
            channel: String::new(),
        }
    }

    pub fn run(&mut self) {
        println!("Client connected");
    }
}
