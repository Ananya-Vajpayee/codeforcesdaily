import sys
 
def main():
    data = sys.stdin.read().split()
    t = int(data[0]); p = 1
    out = []
    for _ in range(t):
        n, k = int(data[p]), int(data[p + 1]); p += 2
        if k < n or k > 2 * n - 1:
            out.append("-1")
            continue
        s = 2 * n - k
        a = [[0] * n for _ in range(n)]
        for i in range(s):
            a[i][i] = i + 1
        cur = s + 1
        for i in range(n):
            for j in range(n):
                if a[i][j] == 0:
                    a[i][j] = cur
                    cur += 1
        for row in a:
            out.append(" ".join(map(str, row)))
    print("\n".join(out))
 
main()