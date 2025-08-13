read = open("mixmilk.in")
write = open("mixmilk.out", "w")

arr = [(0, 0) for _ in range(5)]
for i in range(1, 4):
    c, m = map(int, read.readline().split())
    arr[i] = [c, m]

for i in range(100):
    what = i%3 + 1

    cap = min(arr[what][1], arr[what%3+1][0] - arr[what%3+1][1])
    arr[what][1] = arr[what][1] - cap
    arr[what%3+1][1] = arr[what%3+1][1] + cap

for i in range(1, 4):
    print(arr[i][1], file=write)