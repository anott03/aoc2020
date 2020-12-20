with open('./input') as inFile:
    idx = 0
    count = 0
    for line in inFile:
        if line[idx] == '#':
            count += 1
        idx += 3
        if idx > 30:
            idx = idx % 31
    print(count)

