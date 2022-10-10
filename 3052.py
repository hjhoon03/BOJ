num = [False for i in range(42)]

for i in range(10):
    num[int(input()) % 42] = True

print(num.count(True))
