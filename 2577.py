n = 1

for i in range(3):
    n *= int(input())

n = str(n)
num = [0 for i in range(10)]

for i in n:
    num[int(i)] += 1

for i in num:
    print(i)
