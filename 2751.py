def sorting(lst, n):
    sortingTable = [list() for i in range(10)]

    for i in lst:
        sortingTable[i % (10 ** (n + 1)) // (10 ** n)].append(i)

    sorted = list()
    for i in sortingTable:
        for j in i:
            sorted.append(j)

    return sorted

nums = [int(input()) for i in range(int(input()))]

positiveNums = list()
negativeNums = list()

for i in nums:
    if i < 0:
        negativeNums.append(-i)
    else:
        positiveNums.append(i)

for i in range(7):
    positiveNums = sorting(positiveNums, i)
    negativeNums = sorting(negativeNums, i)

for i in negativeNums[::-1]:
    print(-i)
for i in positiveNums:
    print(i)
