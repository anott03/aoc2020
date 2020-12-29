#!/usr/bin/python
global lines, mask, memory, xidxs
memory = {}

with open("input", 'r') as fp:
    lines = [line.rstrip() for line in fp.readlines()]

def applyVals(addr, v):
    numAddrs = mask.count('X')
    xplace = 0
    addr = list(bin(int(addr[4:-1]))[2:].zfill(36))

    for i in range(2**numAddrs):
        xplace = 0
        p = bin(i)[2:].zfill(numAddrs)
        memAddr = ''
        for (i, ch) in enumerate(mask):
            if ch == '1':
                memAddr += '1'
            elif ch == '0':
                memAddr += addr[i]
            elif ch == 'X':
                memAddr += p[xplace]
                xplace += 1
        memory[str(memAddr)] = int(v)

for line in lines:
    if line[0:4] == 'mask':
        mask = line.split(' = ')[1]
        continue

    _addr, _v = line.split(' = ')
    applyVals(_addr, _v)

#  s = 0
#  for key in memory:
    #  print(key, type(memory[key]))
    #  s += memory[key]
#  print(str(s))
print("PART 2 " + str(sum(memory.values())))
