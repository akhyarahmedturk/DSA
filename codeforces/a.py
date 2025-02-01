import sys

for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())
    data = list(map(int, sys.stdin.readline().split()))
    temp = set()

    for i in range(1, len(data)):
        temp.add(data[i - 1] - data[i])

    if len(temp) == 1 or n == 1:
        print(0)
    elif len(temp) == 2:
        a, b = sorted(temp)
        if a < 0 and b > 0 and b - a > max(data):
            print(b - a, -a)
        else:
            print(-1)
    else:
        print(-1)