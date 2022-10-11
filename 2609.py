def greatestCommonMultiple(num1, num2):
    res = 1
    for i in range(2, min([num1, num2]) + 1):
        if num1 % i == num2 % i == 0:
            res = i

    return res

def leastCommonFactor(num1, num2):
    l = [num1, num2]

    while l[0] != l[1]:
        if l[0] < l[1]:
            l[0] += num1
        else:
            l[1] += num2

    return l[0]

n1, n2 = map(int, input().split())

print(greatestCommonMultiple(n1, n2))
print(leastCommonFactor(n1, n2))
