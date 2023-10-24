// Channel module for the IRC

use std::net::TcpStream;

pub struct Channel {
    pub stream: TcpStream,
    pub nick: String,
    pub user: String,
    pub real_name: String,
    pub channel: String,
}
