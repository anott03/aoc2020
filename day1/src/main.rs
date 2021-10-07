#![allow(dead_code)]
#![allow(unused_must_use)]

use std::{collections::HashMap, fs::File, io::{BufReader, BufRead, Error}};

fn main() {
    let mut values: HashMap<i64, i64> = HashMap::new();
    read_input_file(&mut values);

    part1(&values);
    part2(&values);
}

fn part2(values: &HashMap<i64, i64>) {
    let goal = 2020;
    let mut found = 0;

    for (_, value) in values {
        let needed = goal - value;
        for (_, value2) in values {
            let needed2 = needed - value2;
            match values.get(&needed2) {
                Some(x) => {
                    found = x + value2 + value;
                    println!("THE VALUE IS {}", x * value2 * value);
                    break;
                },
                None => {}
            }
        }
        if found == goal {
            break;
        }
    }
}

fn part1(values: &HashMap<i64, i64>) {
    let goal = 2020;

    for (_, value) in values {
        let needed = goal - value;
        match values.get(&needed) {
            Some(x) => {
                println!("THE VALUE IS {}", x * value);
                break;
            },
            None => {}
        }
    }
}

fn read_input_file(values: &mut HashMap<i64, i64>) -> Result<(), Error> {
    let file = File::open("src/input")?;
    let reader = BufReader::new(file);

    for line in reader.lines() {
        let line: i64 = line.unwrap().parse().unwrap();
        values.insert(line, line);
    }

    return Ok(());
}
