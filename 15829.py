a = int(input())
b = input()
c = 0

for i in range(a) :
    c += (31 ** i) * (ord(b[i]) - 96)

print(c % 1234567891)
