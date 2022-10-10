n = int(input())
score = list(map(int, input().split()))

highScore = max(score)
falseSum = 0

for i in score:
    falseSum += i / highScore * 100

print(falseSum / n)
