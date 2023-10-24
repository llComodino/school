use std::fs::File;
use std::io::{BufRead, BufReader};

fn read_lines (filename: &str) -> Vec<String> {
    let mut lines = Vec::new();
    let file = File::open(filename).expect("file not found");
    let buf = BufReader::new(file);
    for line in buf.lines() {
        lines.push(line.expect("could not parse line"));
    }
    lines
}

fn main () {

    let lines = read_lines("input.txt");

    let mut vec1 = vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    let mut vec2 = vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0];

    for line in lines {

        let mut i : usize = 0;

        if line.len() != 12 {
            continue;
        }

        while i < line.len() {
            
            match line.chars().nth(i).unwrap() {
                '0' => vec1[i] += 1,
                '1' => vec2[i] += 1,
                _ => (),
            }
            i += 1;
        }

    }

    for x in 0..12 {
        if vec1[x] > vec2[x] {
            vec1[x] = 0;
        } else {
            vec1[x] = 1;
        }
    }

    // Invert vec1 values in vec2 
    for x in 0..12 {
        if vec1[x] == 0 {
            vec2[x] = 1;
        } else {
            vec2[x] = 0;
        }
    }

    // Convert vec1 and vec2 to decimal
    let mut vec1_dec = 0;
    let mut vec2_dec = 0;

    for x in 0..12 {
        vec1_dec += vec1[x] * 2_usize.pow(11 - x as u32);
        vec2_dec += vec2[x] * 2_usize.pow(11 - x as u32);
    }

    println!("Consupion: {}", vec1_dec * vec2_dec);
}
