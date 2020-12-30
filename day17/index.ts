import * as fs from 'fs';

let input = fs.readFileSync('./input.test', 'utf-8').trim().split('\n')
let activeCubes = [];
input.forEach((line, i) => {
  line.split('').forEach((c, j) => {
    if (c === '#') activeCubes.push({x: j, y: i, z: 0});
  });
});

for (let _ = 0; _ < 6; _++) {
  let newActiveCubes = [];
  let check = [];
  for (let {x, y, z} of activeCubes) {
    for (let i = 1; i < 27; ++i) {
      let b3 = i.toString(3).padStart(3, '0').split('').reverse();
      const nx = x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
      const ny = y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
      const nz = z + (b3[2] == '2' ? -1 : parseInt(b3[2]));
      check.push({x: nx, y: ny, z: nz});
    }
  }

  for (let {x, y, z} of check) {
    let activeNeighbors = 0;
    for (let i = 1; i < 27; ++i) {
      let b3 = i.toString(3).padStart(3, '0').split('').reverse();
      const nx = x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
      const ny = y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
      const nz = z + (b3[2] == '2' ? -1 : parseInt(b3[2]));
      if (activeCubes.includes({x: nx, y: ny, z: nz})) {
        ++activeNeighbors;
      }
    }

    if (activeCubes.includes({x: x, y: y, z: z})) {
      if (activeNeighbors === 2 || activeNeighbors === 3) newActiveCubes.push({x: x, y: y, z: z});
    } else {
      if (activeNeighbors === 3) newActiveCubes.push({x: x, y: y, z: z});
    }
  }

  console.log(newActiveCubes);
  activeCubes = newActiveCubes;
}

console.log('PART 1', activeCubes.length);


// class Cube {
  // x: number;
  // y: number;
  // z: number;
  // active: boolean;

  // constructor(x: number, y: number, z: number, active: boolean = false) {
    // this.x = x;
    // this.y = y;
    // this.z = z;
    // this.active = active;
  // }
// }

// let input = fs.readFileSync('./input.test', 'utf-8').trim().split('\n')
// let cubes: Map<string, Cube> = new Map();
// let newCubes = new Map();
// let totalActiveCubes = 0;

// for (let i = 0; i < input.length; ++i) {
  // for (let j = 0; j < input[i].length; ++j) {
    // let c: string  = input[i].charAt(j);
    // cubes.set(`x${j}y${i}z0`, new Cube(j, i, 0, c === '#'));
  // }
// }

// function calculateActiveNeighbors(c: Cube) {
  // let activeNeighbors = 0;
  // for (let i = 1; i < 27; ++i) {
    // let b3 = i.toString(3).padStart(3, '0').split('').reverse();
    // const nx = c.x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
    // const ny = c.y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
    // const nz = c.z + (b3[2] == '2' ? -1 : parseInt(b3[2]));

    // const nkey = `x${nx}y${ny}z${nz}`
    // if (cubes.get(nkey)) {
      // if (cubes.get(nkey).active) activeNeighbors++;
    // } else newCubes.set(nkey, new Cube(nx, ny, nz, false));
  // }
  // return activeNeighbors;
// }

// for (let i = 0; i < 1; ++i) {
  // cubes.forEach((cube, key) => {
    // console.log(cube);
    // let activeNeighbors = calculateActiveNeighbors(cube);
    // if (cube.active) {
      // if (activeNeighbors === 2 || activeNeighbors === 3) console.log('remain active');
      // else console.log('become inactive');
    // } else {
      // if (activeNeighbors === 3) console.log('become active');
      // else console.log('remain inactive');
    // }
  // });
// }

// console.log(calculateActiveNeighbors(cubes.get(`x2y1z0`)));

// cubes.forEach((cube, _) => {
  // totalActiveCubes += cube.active ? 1 : 0;
// });

// console.log('PART 1', totalActiveCubes);
