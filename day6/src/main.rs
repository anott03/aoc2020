#![allow(dead_code)]
#![allow(unused_must_use)]

use std::{fs::File, io::{Error, Read}};
use std::collections::HashMap;

fn main() {
    part2();
}

fn part2() {
    let mut input = String::new();
    match read_input_file() {
        Ok(s) => {
            input = s;
        },
        Err(e) => {
            println!("error: {}", e);
        }
    }

    let groups: Vec<&str> = input.split("\n\n").collect();

    let mut count = 0;
    for group in &groups {
        let x = group.split("\n").collect::<Vec<&str>>().len() as i32;
        group.replace("\n", "");

        let mut letter_counts: HashMap<char, i32> = HashMap::new();
        for c in group.chars() {
            match letter_counts.get(&c) {
                Some(_) => {
                    let stat = letter_counts.entry(c).or_insert(1);
                    *stat += 1;
                },
                None => {
                    letter_counts.insert(c, 1);
                }
            }
        }
        for (_, _count) in &letter_counts {
            if *_count == x {
                count += 1;
            }
        }
    }
    println!("count: {}", count);
}

fn part1() {
    let mut input = String::new();
    match read_input_file() {
        Ok(s) => {
            input = s;
        },
        Err(e) => {
            println!("error: {}", e);
        }
    }

    let groups: Vec<&str> = input.split("\n\n").collect();

    let mut count = 0;
    for group in &groups {
        group.replace("\n", "");

        let mut letters = vec!['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
        for c in group.chars() {
            if letters.iter().any(|&i| i==c) {
                let index = letters.iter().position(|x| *x == c).unwrap();
                letters.remove(index);
            }
        }
        count += 26 - letters.len();
    }
    println!("count: {}", count);
}

fn read_input_file() -> Result<String, Error> {
    let mut file = File::open("/home/amitav/dev/advent-of-code-2020/day6/src/input")?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;

    return Ok(contents);
}

fn take_until_char(string: &str, ch: char) -> Result<(&str, &str), Error> {
    let count = string.chars().take_while(|c| {
        return *c != ch;
    }).count();

    return Ok((&string[0..count], &string[count..]));
}

