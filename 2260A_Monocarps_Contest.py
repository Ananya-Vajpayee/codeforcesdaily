t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if a.count(0) < 2:
        print(-1)
    else:
        print(a[0] + a[-1])