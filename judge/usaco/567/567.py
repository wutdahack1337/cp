read = open("paint.in")
write = open("paint.out", "w")

a, b = map(int, read.readline().split(' '))
c, d = map(int, read.readline().split(' '))

ans = (b - a) + (d - c)
if (min(a, c) <= max(a, c) <= min(b, d)):
    ans -= (min(b, d) - max(a, c))

print(ans, file=write)