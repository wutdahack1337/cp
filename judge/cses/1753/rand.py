write = open("input.txt", "w")

from random import randint

n_str = randint(1, 19)
str = ""
for i in range(n_str):
    str += chr(randint(97, 99))

n_pattern = randint(1, 3)
pattern = ""
for i in range(n_pattern):
    pattern += chr(randint(97, 99))

print(str, file=write)
print(pattern, file=write)