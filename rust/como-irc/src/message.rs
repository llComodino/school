// Message module for the IRC

pub struct Message {
    pub prefix: Option<String>,
    pub command: String,
    pub params: Vec<String>,
    pub trail: Option<String>,
}
