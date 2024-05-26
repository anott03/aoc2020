import * as fs from 'fs'

const part1 = (): Map<string, string> => {
  let input = fs.readFileSync('./input.prod', 'utf-8').trim().split('\n')
  let floor = new Map();
  let blackCounter = 0;

  for (let line of input) {
    let pos = {x: 0, y: 0};

    while (line.length > 0) {
      let dir: string = line.charAt(0);
      dir += 'ns'.indexOf(line.charAt(0)) !== -1 ? line.charAt(1) : '';
      let sub_f = dir.length > 1 ? 2 : 1;

      switch (dir) {
        case 'e':
          pos.x += 2;
          break;
        case 'w':
          pos.x -= 2;
          break;
        case 'ne':
          pos.x += 1;
          pos.y += 1;
          break;
        case 'nw':
          pos.x -= 1;
          pos.y += 1;
          break
        case 'se':
          pos.x += 1;
          pos.y -= 1;
          break;
        case 'sw':
          pos.x -= 1;
          pos.y -= 1;
          break;
      }
      line = line.substring(sub_f);
    }

    const key = `x${pos.x}y${pos.y}`;

    if (floor.has(key)) {
      if (floor.get(key) == 'B') {
        floor.set(key, 'W');
        --blackCounter;
      }
      else {
        floor.set(key, 'B');
        ++blackCounter;
      }
    } else {
      floor.set(key, 'B');
      ++blackCounter;
    }
  }

  console.log(`PART 1 ${blackCounter}`)
  return floor;
}

const part2 = (floor: Map<string, string>) => {

  const getAdjacent = (key: string, dir: string) => {
    let x: number = parseInt(key.substring(1, key.indexOf('y')));
    let y: number = parseInt(key.substring(key.indexOf('y') + 1));
    switch (dir) {
      case 'e':
        x += 2;
        break;
      case 'w':
        x -= 2;
        break;
      case 'ne':
        x += 1;
        y += 1;
        break;
      case 'nw':
        x -= 1;
        y += 1;
        break
      case 'se':
        x += 1;
        y -= 1;
        break;
      case 'sw':
        x -= 1;
        y -= 1;
        break;
    }
    return `x${x}y${y}`;
  }

  const dirs = ['e', 'w', 'ne', 'se', 'nw', 'sw'];
  for (let i = 0; i < 100; ++i) {
    const expandedFloor = new Map();
    floor.forEach((v, key, __) => {
      expandedFloor.set(key, v);
      for (let dir of dirs) {
        let adjKey = getAdjacent(key, dir);
        if (!floor.has(adjKey)) expandedFloor.set(adjKey, 'W');
      }
    });

    const newFloor = new Map();
    expandedFloor.forEach((v, key) => {
      newFloor.set(key, v);
      let blackCount = 0;
      for (let dir of dirs) {
        const adjKey = getAdjacent(key, dir);
        if (expandedFloor.get(adjKey) === 'B') ++blackCount;
      }
      if (v == 'B') {
        if (blackCount === 0 || blackCount > 2) newFloor.set(key, 'W');
      } else {
        if (blackCount === 2) newFloor.set(key, 'B');
      }
    });
    floor = newFloor;
  }

  let blackCount = 0;
  floor.forEach((_, key, __) => {
    if (floor.get(key) === 'B') ++blackCount;
  });
  console.log(`PART 2 ${blackCount}`);
}

const initialFloor = part1();
part2(initialFloor);
