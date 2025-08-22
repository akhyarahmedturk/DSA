t = 1
n = 200000
k = 1000000000
val = 10000000

print(t)
for _ in range(t):
    print(f"{n} {k}")
    print(" ".join(str(i) for i in range(n)))
    print(" ".join(str(val+i) for i in range(n)))
