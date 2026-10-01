import sys
input = sys.stdin.readline
 
t = int(input())
res = []
for _ in range(t):
    n, k = map(int, input().split())
    s = input().strip()
    
    if n < 2 * k:
        res.append("-1")
        continue
    
    flips = 0
    for i in range(k):          # positions 1..k -> must be 'R'
        if s[i] != 'R':
            flips += 1
    for i in range(n - k, n):   # positions n-k+1..n -> must be 'L'
        if s[i] != 'L':
            flips += 1
    
    res.append(str(flips))
 
print('\n'.join(res))