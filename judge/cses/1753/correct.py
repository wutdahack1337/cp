str = input()
n_str = len(str)

pattern = input()
n_pattern = len(pattern)

ans = 0
for i in range(n_str):
    clone = str[i:min(n_str, i+n_pattern)]
    
    if clone == pattern:
        ans += 1

print(ans)