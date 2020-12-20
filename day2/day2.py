def part1_isLineValid(line):
    rule, passwd = line.split(':')
    passwd = passwd.strip()

    comps = rule.split(' ')
    char = comps[1]
    mi, ma = comps[0].split('-')
    mi, ma = int(mi), int(ma)

    count = 0
    for c in passwd:
        if c == char:
            count += 1

    print(line)
    print(mi, ma)
    print(count)
    print()

    if count >= mi and count <= ma:
        return 1
    return 0

def part2_isLineValid(line):
    rule, passwd = line.split(':')
    passwd = passwd.strip()
    comps = rule.split(' ')
    char = comps[1]
    i1, i2 = comps[0].split('-')
    i1, i2 = int(i1) - 1, int(i2) - 1

    if (passwd[i1] == char and passwd[i2] != char) \
        or (passwd[i2] == char and passwd[i1] != char):
            return 1
    return 0

def part1():
    count = 0
    with open('input') as inFile:
        for line in inFile:
            count += part1_isLineValid(line)
    print(count)

def part2():
    count = 0
    with open('input') as inFile:
        for line in inFile:
            count += part2_isLineValid(line)
    print(count)


part2()
