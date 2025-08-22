import random

n = random.randint(1, 99)
for i in range(n):
    print(chr(random.randint(ord('a'), ord('c'))), end='')