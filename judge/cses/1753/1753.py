str = input()
pattern = input()
str = pattern + str
n_str = len(str)
n_pattern = len(pattern)

f = [n_str]
l = r = -1
for i in range(1, n_str):
    if l < i <= r:
        if f[i-l] < r - i + 1:
            f.append(f[i-l]) 
            continue

    l = i
    r = max(r, l)
    while (r < n_str and str[r] == str[r-i]):
        r += 1
    r -= 1

    f.append(r - l + 1)

ans = 0
for i in range(n_pattern, n_str):
    if f[i] >= n_pattern:
        ans += 1

print(ans)  