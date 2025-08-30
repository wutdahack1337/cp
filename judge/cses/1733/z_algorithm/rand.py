from random import randint

n_pattern = randint(1, 6)
pattern = ""
for i in range(n_pattern):
    pattern += chr(randint(97, 100))

n_loop = randint(1, 3)
str = ""
for i in range(n_loop):
    str += pattern

n_outlier = randint(1, 9)
for i in range(n_outlier):
    str += chr(randint(97, 100))

print(str)