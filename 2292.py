n = int(input())

if n == 1:
    print(1)
else:
    cnt = 2
    prev = 1
    plus = 6
    while True:
        if prev < n <= prev + plus:
            print(cnt)
            break

        cnt += 1
        prev += plus
        plus += 6
