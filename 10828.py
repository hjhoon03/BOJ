import sys

stack = list()
command = str()

for i in range(int(sys.stdin.readline().rstrip())):
    command = sys.stdin.readline().rstrip()

    if 'push' in command:
        stack.append(int(command.split()[1]))

    elif 'pop' == command:
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())

    elif 'size' == command:
        print(len(stack))

    elif 'empty' == command:
        if len(stack) == 0:
            print(1)
        else:
            print(0)

    elif 'top' == command:
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])
