str = input()
n = len(str)

prefix = ""
for i in range(n):
    prefix += str[i]

    clone = ""
    for j in range(n//len(prefix)):
        clone += prefix
    if n%len(prefix) != 0:
        clone += prefix[:n%len(prefix)]

    if clone == str:
        print(len(prefix), end=' ')