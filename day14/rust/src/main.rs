use std::{fs::File, io::{BufReader, BufRead, Error}};

fn main() {
    match read_input_file() {
        Ok(lines) => {
            part1(lines);
        },
        Err(_) => {}
    }
}

fn part1(lines: Vec<String>) {
    let mut mask: &str;
    for _line in &lines {
        let line = _line.as_str();
        if line.contains("mask") {
            mask = &line[7..];
            println!("{}", mask);
            continue;
        }
        let i1 = line.find('[').unwrap() + 1;
        let i2 = line.find(']').unwrap();
        let address = &line[i1..i2];
        println!("{}", address);
    }
}

fn read_input_file() -> Result<Vec<String>, Error> {
    let file = File::open("/home/amitav/dev/advent-of-code-2020/day14/rust/src/input.prod")?;
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
