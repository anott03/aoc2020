filename = "input.prod"

def part1():
    max_id = -1
    with open(filename) as inFile:
        for line in inFile:
            row = 0
            row_pow = 64
            seat = 0
            seat_pow = 4

            for c in line:
                if c == 'B':
                    row += row_pow
                    row_pow /= 2
                elif c == 'F':
                    row_pow /= 2

                if c == 'R':
                    seat += seat_pow
                    seat_pow /= 2
                elif c == 'L':
                    seat_pow /= 2
            
            seatId = row * 8 + seat
            max_id = max(max_id, seatId)
    print(max_id)

def part2():
    ids = []
    with open(filename) as inFile:
        for line in inFile:
            row = 0
            row_pow = 64
            seat = 0
            seat_pow = 4

            for c in line:
                if c == 'B':
                    row += row_pow
                    row_pow /= 2
                elif c == 'F':
                    row_pow /= 2

                if c == 'R':
                    seat += seat_pow
                    seat_pow /= 2
                elif c == 'L':
                    seat_pow /= 2
            
            seatId = row * 8 + seat
            ids.append(seatId)

        for id_ in ids:
            if id_+1 not in ids and id_+2 in ids:
                print(id_ + 1)

part2()

#  from math import ceil as ceil

#  def parseRow(line):
    #  s, e = 0, 127
    #  linecp = line
    #  while len(linecp) > 0:
        #  if linecp[0] == 'F':
            #  e = ceil((s + e) / 2)
        #  elif linecp[0] == 'B':
            #  s = ceil((s + e) / 2)
        #  linecp = linecp[1:]
    #  if line[6] == 'F':
        #  return s
    #  elif line[6] == 'B':
        #  return e
    #  return e


#  def parseSeat(line):
    #  s, e = 0, 7
    #  linecp = line
    #  while len(linecp) > 0:
        #  if linecp[0] == 'L':
            #  e = ceil((s + e) / 2)
        #  elif linecp[0] == 'R':
            #  s = ceil((s + e) / 2)
        #  linecp = linecp[1:]
    #  if line[2] == 'L':
        #  return s
    #  elif line[2] == 'R':
        #  return e
    #  return e

#  filename = "input.prod"
#  with open(filename) as inFile:
    #  max_val = -1
    #  i = 0
    #  for line in inFile:
        #  row = parseRow(line[0:7])
        #  seat = parseSeat(line[6:9])
        #  seatId = (row * 8) + seat
        #  print(filename + str(i))
        #  print("row", row)
        #  print("seat", seat)
        #  print("seatid", seatId)
        #  print()
        #  i += 1
        #  if seatId > max_val:
            #  max_val = seatId
    #  print("max:", max_val)


