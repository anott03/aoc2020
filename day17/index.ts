import * as fs from 'fs';

class Cube {
  x: number;
  y: number;
  z: number;
  active: boolean;

  constructor(x: number, y: number, z: number, active: boolean = false) {
    this.x = x;
    this.y = y;
    this.z = z;
    this.active = active;
  }

}

let input = fs.readFileSync('./input.test', 'utf-8').trim().split('\n')
let cubes: Cube[] = [];

for (let i = 0; i < input.length; ++i) {
  for (let j = 0; j < input[i].length; ++j) {
    let c: string  = input[i].charAt(j);
    cubes.push(new Cube(j, i, 0, c == '#'));
  }
}

console.log(fs.readFileSync('./input.test', 'utf-8').trim());
for (let cube of cubes) {
  console.log(cube.x, cube.y, cube.z, cube.active);
}
