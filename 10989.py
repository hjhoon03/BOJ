import sys

cnt = [0 for _ in range(10000)]

for i in range(int(sys.stdin.readline())):
    cnt[int(sys.stdin.readline()) - 1] += 1

for i in enumerate(cnt):
    for _ in range(i[1]):
        print(i[0] + 1)
