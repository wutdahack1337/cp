str = input()
n = len(str)
 
pattern = str
f = [n]
l = r = -1
for i in range(1, n):
    if l < i <= r:
        if f[i-l] < r-i+1:
            f.append(f[i-l])
            continue
    
    l = i
    r = max(r, l)
    while (r <= n-1 and str[r] == str[r-i]):
        r += 1
    r -= 1
 
    f.append(r - l + 1)
 
    if r == n-1:
        print(i, end=' ')
 
print(n, end=' ')