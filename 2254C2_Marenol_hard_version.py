import sys
input = sys.stdin.readline
 
def solve():
    n = int(input())
    a = input().strip()
    b = input().strip()
    
    total = 0
    for k in range(2):  # k = 0: even indices, k = 1: odd indices
        p1 = [i for i in range(k, n, 2) if a[i] == '1']
        p2 = [i for i in range(k, n, 2) if b[i] == '1']
        if len(p1) != len(p2):
            print(-1)
            return
        total += sum(abs(x - y) for x, y in zip(p1, p2))
    
    print(total // 2)
 
t = int(input())
for _ in range(t):
    solve()