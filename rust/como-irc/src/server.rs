// Server module for the IRC chat
use std::sync::{Arc, Mutex};
use std::collections::HashMap;

extern crate irc;

use irc::client::prelude::*;
use irc::client::data::*;

use super::channel::Channel;

pub struct Server {
    pub config: Config,
    pub users: Arc<Mutex<HashMap<String, User>>>,
    pub channels: Arc<Mutex<HashMap<String, Channel>>>,
}

impl Server {

    pub fn new() -> Server {
        Server {
            config: Config {
                nickname: Some("rusty".to_owned()),
                server: Some("irc.freenode.net".to_owned()),
                channels: vec!["#rusty".to_owned()],
                .. Default::default()
            },
            users: Arc::new(Mutex::new(HashMap::new())),
            channels: Arc::new(Mutex::new(HashMap::new())),
        }
    }
}
