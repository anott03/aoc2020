#![allow(dead_code)]
#![allow(unused_must_use)]

use std::{fs::File, io::{BufReader, BufRead, Error}};

fn main() {
    match read_input_file() {
        Ok(values) => {
            part1(values);
        },
        Err(_) => {}
    }
}

fn evaluate(exp: String) -> i64 {
    match exp.find(")") {
        Some(idx) => {
            // println!("{}", exp.as_bytes()[idx] as char);
            let close_idx = idx;
            let mut open_idx: usize = 0;
            for i in (0..idx).rev() {
                if exp.as_bytes()[i] as char == '(' {
                    open_idx = i + 1;
                    break;
                }
            }
            let sub_ans = evaluate((&exp[open_idx..close_idx]).to_string());
            // println!("{}", sub_ans);
        },
        None => {
            // remove_whitespace(&mut exp);
            let tokens = exp.split(" ");
            let mut op: char = '!';
            let mut result = 0;
            for token in tokens {
                if token != "*" && token != "+" {
                    if op == '!' {
                        result = token.parse::<i64>().unwrap();
                        continue;
                    }
                    if op == '*' {
                        result *= token.parse::<i64>().unwrap();
                        continue;
                    }
                    if op == '+' {
                        result += token.parse::<i64>().unwrap();
                        continue;
                    }
                } else {
                    op = token.as_bytes()[0] as char;
                }
            }
            // println!("res {}", result);
            return result;
        },
    }

    return -1;
}

fn part1(values: Vec<String>) {
    // let mut sum: i64 = 0;
    for exp in values {
        let val = evaluate(exp.clone());
        println!("{} {}", exp.clone(), val);
    }
    // println!("PART 1 {}", sum);
}

fn read_input_file() -> Result<Vec<String>, Error> {
    let file = File::open("input.test")?;
    let reader = BufReader::new(file);
    let mut values: Vec<String> = Vec::new();

    for line in reader.lines() {
        match line {
            Ok(l) => {
                values.push(l.to_string());
            },
            Err(_) => {}
        }
    }

    return Ok(values);
}

fn remove_whitespace(s: &mut String) {
    s.retain(|c| !c.is_whitespace());
}
