import sys
input = sys.stdin.readline
 
t = int(input())
res = []
for _ in range(t):
    n, k = map(int, input().split())
    s = input().strip()
    cnt = 0
    for i in range(0, n, k):
        chunk = s[i:i+k]
        if '0' not in chunk:
            cnt += 1
    res.append(str(cnt))
 
print('\n'.join(res))