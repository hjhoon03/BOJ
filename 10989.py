cnt = [0 for _ in range(10000)]

for i in range(int(input())):
    cnt[int(input()) - 1] += 1;

for i in range(10000):
    for j in range(cnt[i]):
        print(i + 1)
