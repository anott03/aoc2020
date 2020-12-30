import * as fs from 'fs';

const part1 = () => {
  let input = fs.readFileSync('./input.prod', 'utf-8').trim().split('\n')
  let activeCubes = new Set();
  input.forEach((line, i) => {
    line.split('').forEach((c, j) => {
      if (c === '#') {
        activeCubes.add(`x${j}y${i}z0`);
        console.log(j, i, 0);
      }
    });
  });

  for (let _ = 0; _ < 6; _++) {
    let newActiveCubes = new Set();
    let check = new Set();
    activeCubes.forEach((s: string) => {
      let x = parseInt(s.substring(1, s.indexOf('y')));
      let y = parseInt(s.substring(s.indexOf('y') + 1, s.indexOf('z')));
      let z = parseInt(s.substring(s.indexOf('z') + 1));
      for (let i = 1; i < 27; ++i) {
        let b3 = i.toString(3).padStart(3, '0').split('').reverse();
        const nx = x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
        const ny = y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
        const nz = z + (b3[2] == '2' ? -1 : parseInt(b3[2]));
        check.add(`x${nx}y${ny}z${nz}`);
      }
    });

    check.forEach((s: string) => {
      let activeNeighbors = 0;
      let x = parseInt(s.substring(1, s.indexOf('y')));
      let y = parseInt(s.substring(s.indexOf('y') + 1, s.indexOf('z')));
      let z = parseInt(s.substring(s.indexOf('z') + 1));
      for (let i = 1; i < 27; ++i) {
        let b3 = i.toString(3).padStart(3, '0').split('').reverse();
        const nx = x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
        const ny = y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
        const nz = z + (b3[2] == '2' ? -1 : parseInt(b3[2]));

        if (activeCubes.has(`x${nx}y${ny}z${nz}`)) {
          ++activeNeighbors;
        }
      }

      if (activeCubes.has(`x${x}y${y}z${z}`)) {
        if (activeNeighbors === 2 || activeNeighbors === 3) newActiveCubes.add(`x${x}y${y}z${z}`);
      } else {
        if (activeNeighbors === 3) newActiveCubes.add(`x${x}y${y}z${z}`);
      }
    });

    console.log(newActiveCubes);
    activeCubes = newActiveCubes;
  }
  console.log('PART 1', activeCubes.size);
}

const part2 = () => {
  let input = fs.readFileSync('./input.test', 'utf-8').trim().split('\n')
  let activeCubes = new Set();
  input.forEach((line, i) => {
    line.split('').forEach((c, j) => {
      if (c === '#') {
        activeCubes.add(`x${j}y${i}z0w0`);
      }
    });
  });

  for (let _ = 0; _ < 6; _++) {
    let newActiveCubes = new Set();
    let check = new Set();
    activeCubes.forEach((s: string) => {
      let x = parseInt(s.substring(1, s.indexOf('y')));
      let y = parseInt(s.substring(s.indexOf('y') + 1, s.indexOf('z')));
      let z = parseInt(s.substring(s.indexOf('z') + 1, s.indexOf('w')));
      let w = parseInt(s.substring(s.indexOf('z') + 1));
      for (let i = 1; i < Math.pow(4, 4); ++i) {
        let b3 = i.toString(4).padStart(3, '0').split('').reverse();
        const nx = x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
        const ny = y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
        const nz = z + (b3[2] == '2' ? -1 : parseInt(b3[2]));
        check.add(`x${nx}y${ny}z${nz}`);
      }
    });

    check.forEach((s: string) => {
      let activeNeighbors = 0;
      let x = parseInt(s.substring(1, s.indexOf('y')));
      let y = parseInt(s.substring(s.indexOf('y') + 1, s.indexOf('z')));
      let z = parseInt(s.substring(s.indexOf('z') + 1));
      for (let i = 1; i < 27; ++i) {
        let b3 = i.toString(3).padStart(3, '0').split('').reverse();
        const nx = x + (b3[0] == '2' ? -1 : parseInt(b3[0]));
        const ny = y + (b3[1] == '2' ? -1 : parseInt(b3[1]));
        const nz = z + (b3[2] == '2' ? -1 : parseInt(b3[2]));

        if (activeCubes.has(`x${nx}y${ny}z${nz}`)) {
          ++activeNeighbors;
        }
      }

      if (activeCubes.has(`x${x}y${y}z${z}`)) {
        if (activeNeighbors === 2 || activeNeighbors === 3) newActiveCubes.add(`x${x}y${y}z${z}`);
      } else {
        if (activeNeighbors === 3) newActiveCubes.add(`x${x}y${y}z${z}`);
      }
    });

    console.log(newActiveCubes);
    activeCubes = newActiveCubes;
  }
  console.log('PART 1', activeCubes.size);
}

// part1();
part2();
