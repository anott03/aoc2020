#![allow(dead_code)]

use std::{fs::File, io::{BufReader, BufRead, Error}};

fn main() {
    match read_input_file() {
        Ok(input) => {
            part1(input);
        },
        Err(_) => {}
    }
}

fn solve(exp: String) -> i64 {
    let result = 0;
    return result;
}

fn part1(input: Vec<String>) {
    let mut sum = 0;
    for line in input {
        sum += solve(line);
    }
    println!("PART 1 {}", sum);
}

fn take_until_char(string: &str, ch: char) -> Result<(&str, &str), Error> {
    let count = string.chars().take_while(|c| {
        return *c != ch;
    }).count();

    return Ok((&string[0..count], &string[count..]));
}

fn read_input_file() -> Result<Vec<String>, Error> {
    let file = File::open("/home/amitav/dev/advent-of-code-2020/day18/rust/src/input.test")?;
    let reader = BufReader::new(file);
    let mut lines: Vec<String> = Vec::new();
    for line in reader.lines() {
        match line {
            Ok(s) => {
                lines.push(s);
            },
            Err(_) => {}
        }
    }

    return Ok(lines);
}
