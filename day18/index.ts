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

function part2() {
  input = fs.readFileSync('./input.prod', 'utf-8').trim().split('\n');
  const solve = (line: string): number => {
    let tokens = line.split('/');

    while (tokens.includes('(')) {
      let close_idx = tokens.indexOf(')');
      let open_idx = tokens.slice(0, close_idx).lastIndexOf('(');
      tokens = [...tokens.slice(0, open_idx),
        solve(tokens.slice(open_idx + 1, close_idx).join('/')).toString(),
      ...tokens.slice(close_idx + 1)]
    }

    while (tokens.includes('+')) {
      let multIdx = tokens.indexOf('+');
      let s = parseInt(tokens[multIdx - 1]) + parseInt(tokens[multIdx + 1]);
      tokens = [...tokens.slice(0, multIdx - 1), s.toString(), ...tokens.slice(multIdx + 2)];
    }

    let ans = 1;
    tokens.forEach((token: string, _) => {
      if (token !== '*') ans *= parseInt(token);
    });

    return ans;
  }

  let sum = 0;
  for (let line of input) {
    let x = solve(line.replace(/ /g, '').split('').join('/'));
    sum += x;
  }
  console.log('PART 2', sum);
}

part1();
part2();
