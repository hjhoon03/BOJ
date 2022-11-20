import sys

queue = list()
command = str()

for i in range(int(sys.stdin.readline().rstrip())):
    command = sys.stdin.readline().rstrip()

    if 'push' in command:
        queue.append(int(command.split()[1]))

    elif 'pop' == command:
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
            del queue[0]

    elif 'size' == command:
        print(len(queue))

    elif 'empty' == command:
        if len(queue) == 0:
            print(1)
        else:
            print(0)

    elif 'front' == command:
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])

    elif 'back' == command:
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
