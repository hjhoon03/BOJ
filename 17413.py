words = input()
word = ''
basket_flag = False

for i in words:
    if not basket_flag and i == ' ':
        print(word[::-1], end=' ')
        word = ''
    elif i == '<':
        print(word[::-1], end='')
        word = ''
        word += ('<')
        basket_flag = True
    elif i == '>':
        word += ('>')
        print(word, end='')
        word = ''
        basket_flag = False
    else:
        word += i

print(word[::-1], end='')
