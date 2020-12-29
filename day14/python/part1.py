with open("input", 'r') as fp:
    lines = [line.rstrip() for line in fp.readlines()]

memory = {}
mask = None

for line in lines:
    k, v = line.split(" = ")
    if k == "mask":
        mask = v
    else:
        address = int(k[4:-1])
        value = int(v)       

        bin_value = list(bin(value)[2:].zfill(36))

        for i in range(len(mask)):
            if not mask[i] == 'X':
                bin_value[i] = mask[i]

        memory[address] = int("".join(bin_value), 2)

print(f"PART 1 {sum(memory.values())}")    

