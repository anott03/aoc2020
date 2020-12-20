use std::{fs::File, io::{BufReader, BufRead, Error}};

fn main() {
    match read_input_file() {
        Ok((estimate, values)) => {
            // println!("{}\n{:?}", estimate, values);
            part1(estimate, values.clone());
            part2(values.clone());
        },
        Err(_) => {}
    }
}

fn part2(ids: Vec<i64>) {
}

fn part1(estimate: i64, ids: Vec<i64>) {
    let mut min = ids[0] - estimate % ids[0];
    let mut min_id = ids[0];
    for id in &ids {
        if *id != -1 {
            let wait_time = id - estimate % id;
            if wait_time < min {
                min = wait_time;
                min_id = *id;
            }
        }
    }
    println!("PART 1: {}", min * min_id);
}

fn read_input_file() -> Result<(i64, Vec<i64>), Error> {
    let file = File::open("/home/amitav/dev/advent-of-code-2020/day13/src/input")?;
    let reader = BufReader::new(file);
    let mut values: Vec<i64> = Vec::new();

    let mut lines: Vec<String> = Vec::new();
    for line in reader.lines() {
        match line {
            Ok(s) => {
                lines.push(s);
            },
            Err(_) => {}
        }
    }

    let mut estimate: i64 = -1;
    match lines[0].parse::<i64>() {
        Ok(n) => { estimate = n; },
        Err(_) => {}
    }

    lines[1] = lines[1].replace("x", "-1");
    for val in lines[1].split(",").collect::<Vec<&str>>() {
        match val.parse::<i64>() {
            Ok(x) => { values.push(x); },
            Err(_) => {}
        }
    }

    return Ok((estimate, values));
}


// fn egcd(a: i64, b: i64) -> (i64, i64, i64) {
    // if a == 0 {
        // (b, 0, 1)
    // } else {
        // let (g, x, y) = egcd(b % a, a);
        // (g, y - (b / a) * x, x)
    // }
// }
 
// fn mod_inv(x: i64, n: i64) -> Option<i64> {
    // let (g, x, _) = egcd(x, n);
    // if g == 1 {
        // Some((x % n + n) % n)
    // } else {
        // None
    // }
// }
 
// fn chinese_remainder(residues: &[i64], modulii: &[i64]) -> Option<i64> {
    // let prod = modulii.iter().product::<i64>();
 
    // let mut sum = 0;
 
    // for (&residue, &modulus) in residues.iter().zip(modulii) {
        // let p = prod / modulus;
        // sum += residue * mod_inv(p, modulus)? * p
    // }
 
    // Some(sum % prod)
// }
 
