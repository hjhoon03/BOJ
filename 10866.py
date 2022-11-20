import sys

deque = list()
command = str()

for i in range(int(sys.stdin.readline().rstrip())):
    command = sys.stdin.readline().rstrip()

    if 'push_front' in command:
        deque.append(int(command.split()[1]))

    elif 'push_back' in command:
        deque.insert(0, ))

    elif 'pop' == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
            del deque[0]

    elif 'size' == command:
        print(len(deque))

    elif 'empty' == command:
        if len(deque) == 0:
            print(1)
        else:
            print(0)

    elif 'front' == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])

    elif 'back' == command:
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[-1])
