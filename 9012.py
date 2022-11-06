for s in [input() for _ in range(int(input()))]:
    if s.count('(') == s.count(')') and s[0] == '(' and s[-1] == ')':
        print('YES')
    else:
        print('NO')
