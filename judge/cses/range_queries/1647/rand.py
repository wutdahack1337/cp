from random import randint

n = 1000
q = 1000
max_x = 1000_000_000


print(n, q)
for i in range(n):
    print(randint(1, max_x), end=' ')
print()

for i in range(q):
    l = randint(1, n)
    r = randint(l, n)
    print(l, r)
        