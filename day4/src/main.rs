#![allow(dead_code)]
#![allow(unused_must_use)]

use std::fs::File;
use std::io::{Error, Read};

fn main() {
    let mut content = String::new();
    match read_input_file() {
        Ok(x) => {
            content = x;
        },
        Err(error) =>  {
            println!("error opening file: {}", error);
        }
    }

    let entries: Vec<&str> = content.split("\n\n").collect();
    // part1(&entries);
    part2(&entries);
}

fn part2(entries: &Vec<&str>) {
    let mut count = 0;
    let keys = vec!["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"];
    for entry in entries {
        let tmp = entry.replace("\n", " ");
        let values: Vec<&str> = tmp.split(" ").collect();
        let mut valid = values.len() >= keys.len();

        for key in &keys {
            if !entry.contains(key) {
                valid = false;
                break;
            }
        }

        for value in &values {
            let parts: Vec<&str> = value.split(":").collect();
            if parts.len() == 2 {
                let key = parts[0];
                let val = parts[1];

                match key {
                    "byr" => {
                        let n = val.parse::<i32>().unwrap();
                        if n < 1920 || n > 2002 {
                            valid = false;
                        }
                    },
                    "iyr" => {
                        let n = val.parse::<i32>().unwrap();
                        if n < 2010 || n > 2020 {
                            valid = false;
                        }
                    },
                    "eyr" => {
                        let n = val.parse::<i32>().unwrap();
                        if n < 2020 || n > 2030 {
                            valid = false;
                        }
                    },
                    "hgt" => {
                        if parts[1].contains("cm") {
                            match take_until_char(parts[1], 'c') {
                                Ok((x, _)) => {
                                    let n = x.parse::<i32>().unwrap();
                                    if n < 150 || n > 193 {
                                        valid = false;
                                    }
                                },
                                Err(_) => { valid = false; }
                            }
                        } else if parts[1].contains("in") {
                            match take_until_char(parts[1], 'i') {
                                Ok((x, _)) => {
                                    let n  =x.parse::<i32>().unwrap();
                                    if n < 59 || n > 76 {
                                        valid = false;
                                    }
                                },
                                Err(_) => { valid = false; }
                            }
                        } else {
                            valid = false;
                        }
                    },
                    "hcl" => {

                    },
                    "ecl" => {
                        let eye_colors = vec!["amb", "blu", "gry", "grn", "hzl", "oth"];
                        if !eye_colors.iter().any(|&i| i == parts[1]) {
                            valid = false;
                        }
                    }, 
                    "pid" => {
                        let x = parts[1].chars().take_while(|c| {
                            return c.is_numeric();
                        }).count();
                        if x != 9 {
                            valid = false;
                        }
                    },
                    "cid" => {}
                    _ => {}
                }
            }
        }

        if valid {
            count += 1;
        }
    }

    println!("COUNT: {}", count);
}

fn part1(entries: &Vec<&str>) {
    let mut count = 0;

    let keys = vec!["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"];

    for entry in entries {
        let mut valid = true;
        for key in &keys {
            if !entry.contains(key) {
                valid = false;
                break;
            }
        }
        if valid {
            count += 1;
        }
    }

    println!("COUNT: {}", count);
}

fn read_input_file() -> Result<String, Error> {
    let mut file = File::open("/home/amitav/dev/advent-of-code-2020/day4/src/input")?;
    let mut content = String::new();
    file.read_to_string(&mut content)?;
    return Ok(content);
}

fn take_until_char(string: &str, ch: char) -> Result<(&str, &str), Error> {
    let count = string.chars().take_while(|c| {
        return *c != ch;
    }).count();

    return Ok((&string[0..count], &string[count..]));
}

