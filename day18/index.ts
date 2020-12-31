import * as fs from 'fs';

let input = fs.readFileSync('./input.prod', 'utf-8').trim().split('\n')

function part1() {
  const solve = (line: string) => {
    let tokens = line.replace(/ /g, '').split('');
    let op: string;
    let result: number;
    for (let i = 0; i < tokens.length; i++) {
      let token = tokens[i];
      if (token === '(') {
        let [sub_sol, idx] = solve(tokens.slice(i + 1).join(""));
        if (!op || !result) result = sub_sol;
        else if (op === "+") result += sub_sol;
        else result *= sub_sol;
        i += idx + 1;
      } else if (token === ")") {
        return [result, i];
      }
      else if (token === "*" || token === "+") {
        op = token;
      }
      else {
        if (!op || !result) result = parseInt(token);
        else if (op === "+") result += parseInt(token);
        else result *= parseInt(token);
      }
    }
    return [result, NaN];
  }

  let sum = 0;
  for (let line of input) {
    sum += solve(line)[0];
  }
  console.log('PART 1', sum);
}
part1();
