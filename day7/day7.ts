import * as fs from 'fs';

fs.readFile('./input.test', 'utf8', function(err, data) {
  if (err) {
    console.error(err);
  }

  const lines = data.split("\n");
  console.log(lines);

  for (let line of lines) {
    const color = line.substring(0, line.indexOf("bag"));
    console.log(color);
  }
});
