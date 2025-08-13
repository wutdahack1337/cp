read = open("shell.in")

n = int(read.readline())

arr = []
for i in range(n):
	a, b, g = map(int, read.readline().split())
	arr.append((a, b, g))

ans = 0
for pebble_start_location in range(1, 4):
	pebble_location = pebble_start_location
	score = 0

	for a, b, g in arr:
		if (a == pebble_location):
			pebble_location = b
		elif (b == pebble_location):
			pebble_location = a

		if (g == pebble_location):
			score += 1

	ans = max(ans, score)

print(ans, file=open("shell.out", "w"))