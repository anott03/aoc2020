lines = []
prev_lines = []

def applyRules(iter):
    if iter % 2 == 1:
        for line in lines:
            pass

with open('./input') as inp:
    for line in inp:
        lines.append(line)
    prev_lines = lines
