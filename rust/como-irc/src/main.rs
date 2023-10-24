// IRC server implementation in Rust
mod server;
mod client;
mod channel;
mod message;

use std::net::TcpListener;
use std::thread;
use std::sync::{Arc, Mutex};

use server::Server;
use client::Client;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:6667").unwrap();
    let server = Arc::new(Mutex::new(Server::new()));

    for stream in listener.incoming() {
        let _server = server.clone();
        thread::spawn(move || {
            let mut client = Client::new(stream.unwrap());
            client.run();
        });
    }

    drop(listener);

    println!("Shutting down.");
}
