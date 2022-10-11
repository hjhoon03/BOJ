def makeSum(n):
    sum = n
    n = str(n)

    for i in n:
        sum += int(i)

    return sum


n = int(input())
exist = False

for i in range(n):
    if makeSum(i) == n:
        print(i)
        exist = True
        break

if not exist:
    print(0)
