import * as fs from 'fs'
const lines = fs.readFileSync('../input.test', 'utf-8').trim().split('\n')

const evaluate = (line: string) => {
  while (line.indexOf('(') !== 0) {
    const open_idx = line.lastIndexOf('(');
    let close_idx: number;
    for (let i = open_idx; i < line.length; ++i) {
      if (line.charAt(i) === ')') {
        close_idx = i;
        break;
      }
    }
    // const sub_answer = evaluate(line.substring(open_idx + 1, close_idx));
    // console.log(line.substring(open_idx + 1, close_idx));
    line = line.substring(0, open_idx) + 0 + 
      line.substring(close_idx + 1);
    console.log(line);
  }
  let tokens = line.split(' ');
  let result: number = parseInt(tokens[0]);
  for (let i = 1; i < tokens.length; i += 2) {
    if (tokens[i] == '*') result *= parseInt(tokens[i+1]);
    else if (tokens[i] == '+') result += parseInt(tokens[i+1]);
  }
  console.log(tokens);
  return result;
}

let sum = 0;
lines.forEach(line => {
  sum += evaluate(line);
});
