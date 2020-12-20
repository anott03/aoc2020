use std::{fs::File, io::{BufReader, BufRead, Error}};

fn main() {
    let mut values: Vec<i64>;
    match read_input_file() {
        Ok(vals) => {
            values = vals;
            values.sort();
            values.push(values[values.len()-1]+3);
            part1(&mut values);
            part2(&mut values);
        },
        Err(error) => {
            println!("reading file failed: {}", error);
        }
    }
}

fn part2(values: &mut Vec<i64>) {
    let mut diffs: Vec<i64> = vec![1];
    values.insert(0, 0);
    for i in 1..(values.len()) {
        let mut j = 1;
        let mut diffsum = 0;
        while j <= i && values[i] - values[i - j] <= 3 {
            diffsum += diffs[i - j];
            j += 1;
        }
        diffs.push(diffsum);
    }
    println!("PART 2 {}", diffs[diffs.len()-1]);
}

fn part1(values: &mut Vec<i64>) {
    let mut count1: i64  = 0;
    let mut count3: i64  = 0;

    for i in 0..(values.len() - 1) {
        if values[i + 1] - values[i] == 1 {
            count1 += 1;
        } else if values[i + 1] - values[i] == 3 {
            count3 += 1;
        }
    }
    if values[0] == 1 {
        count1 += 1;
    } else if values[0] == 3 {
        count3 += 1;
    }

    println!("PART 1 {}", count1 * count3);
}

fn read_input_file() -> Result<Vec<i64>, Error> {
    let file = File::open("/home/amitav/dev/advent-of-code-2020/day10/src/input")?;
    let reader = BufReader::new(file);
    let mut values: Vec<i64> = Vec::new();

    for line in reader.lines() {
        let line: i64 = line.unwrap().parse().unwrap();
        values.push(line);
    }

    return Ok(values);
}
