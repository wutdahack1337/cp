from random import randint

n = 1000
q = 1000
max_x = 1_000_000_000


print(n, q)
for i in range(n):
    print(randint(1, max_x), end=' ')
print()

for i in range(q):
    type = randint(1, 3)
    if type == 1:
        print(1, randint(1, n), randint(1, max_x))
    else:
        l = randint(1, n)
        r = randint(l, n)
        print(2, l, r)