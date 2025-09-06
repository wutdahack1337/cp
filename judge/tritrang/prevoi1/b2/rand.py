from random import randint

MAXY = 4
MAXN = 4*MAXY*MAXY-1

n = randint(4, MAXN)
print(n)

marked = [[0 for _ in range(2*MAXY+5)] for _ in range(2*MAXY+5)]

while (n):
    x = randint(-MAXY, MAXY)
    y = randint(-MAXY, MAXY)

    while (marked[x+MAXY][y+MAXY] == 1):
        x = randint(-MAXY, MAXY)
        y = randint(-MAXY, MAXY)

    marked[x+MAXY][y+MAXY] = 1
    print(x, y, randint(1, 4))

    n -= 1