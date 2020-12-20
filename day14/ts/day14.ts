import * as fs from 'fs';

fs.readFile('./input.prod', 'utf8', function(err, data) {
  if (err) {
    console.error(err);
  }
  part1(data);
});

function part1(data: string) {
  const lines = data.split("\n");
  let mask = lines[0].substring(7);
  let memory = {};

  for (let i = 1; i < lines.length; i++) {
    if (lines[i].trim() == "") continue;
    // if (lines.indexOf("mask") !== -1) {
      // mask = lines[i].substring(7);
      // continue;
    // }

    const address = parseInt(lines[i].substring(lines[i].indexOf('[') + 1,
                                                lines[i].indexOf(']')));
    const binaryValue = parseInt(lines[i].substring(lines[i].indexOf('=') + 2)).toString(2);
    memory[address] = applyMask(binaryValue, mask);
  }

  console.log(memory);

  let sum = 0;
  for (const key in memory) {
    sum += memory[key];
  }
  console.log("PART 1", sum);
}

function applyMask(binaryValue: string, mask: string): number {
  while (binaryValue.length !== 36) {
    binaryValue = "0" + binaryValue;
  }

  for (let i = 0; i < mask.length; i++) {
    if (mask.charAt(i) !== 'X') {
      const part1 = binaryValue.substring(0, i);
      const part2 = binaryValue.substring(i + 1);
      binaryValue = part1 + mask.charAt(i) + part2;
    }
  }

  return parseInt(binaryValue, 2);
}
