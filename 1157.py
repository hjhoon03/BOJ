s = input().lower()
alpha = [0 for i in range(26)]

for i in s:
    alpha[ord(i) - ord('a')] += 1

max = max(alpha)
max_idx = alpha.index(max)
flag = True

for i in alpha[max_idx + 1:]:
    if i == max:
        print('?')
        flag = False
        break

if flag:
    print(chr(ord('A') + max_idx))
