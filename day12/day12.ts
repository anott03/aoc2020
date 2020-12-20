import * as fs from 'fs';

fs.readFile('./input', 'utf8', function(err: any, data: string) {
  if (err) {
    console.error(err);
  }
  const commands: string[] = data.split("\n");
  let pos = { x: 0, y: 0, d: 'E' };

  for (let cmd of commands) {
    if (cmd.trim() !== "") {
      const c = cmd.charAt(0);
      const mag: number = parseInt(cmd.substring(1));

      switch (c) {
        case 'R':
          for (let i = 0; i < mag/90; i++) {
            pos = nextDir(pos);
          }
          break;
        case 'L':
          for (let i = 0; i < 4-(mag/90); i++) {
            pos = nextDir(pos);
          }
          break;
      }

    }
  }
  console.log("PART 1 " + (Math.abs(pos.x) + Math.abs(pos.y)) + " " + pos.d);
});

const nextDir = (pos: {x: number, y: number, d: string}) => {
  if (pos.d == 'N') return {...pos, d: 'E'};
  if (pos.d == 'E') return {...pos, d: 'S'};
  if (pos.d == 'S') return {...pos, d: 'W'};
  if (pos.d == 'W') return {...pos, d: 'N'};
}

