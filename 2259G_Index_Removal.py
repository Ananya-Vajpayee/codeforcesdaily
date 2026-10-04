import sys
input = sys.stdin.readline
 
def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    vec2 = [a[j] - j * k for j in range(n)]
    prefix = [0] * n
    prefix[0] = a[0]
    for j in range(1, n):
        prefix[j] = prefix[j-1] + a[j]
    
    ans = [0] * n
    for i in range(1, n - 1):
        target = a[i-1] - i * k
        lo, hi = i + 1, n - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if vec2[mid] <= target:
                hi = mid - 1
            else:
                lo = mid + 1
        num_needed = lo - i - 1
        if num_needed > 0:
            ans[i] = (prefix[i + num_needed] - prefix[i]) \
                     - k * (num_needed * (num_needed + 1) // 2) \
                     - a[i-1] * num_needed
    
    print(*ans)
 
t = int(input())
for _ in range(t):
    solve()