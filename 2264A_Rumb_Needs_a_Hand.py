t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    b = [i + 1 for i in range(n) if p[i] != i + 1]
    k = len(b)
    ok = all(p[b[j] - 1] == b[k - 1 - j] for j in range(k))
    print("YES" if ok else "NO")