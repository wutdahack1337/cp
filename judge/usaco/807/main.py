read = open("teleport.in")
write = open("teleport.out", "w")

a, b, x, y = map(int, read.readline().split(' '))
print(min(abs(b-a), abs(x-a) + abs(b-y), abs(a-y) + abs(b-x)), file=write)