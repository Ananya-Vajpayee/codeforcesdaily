import sys
from collections import Counter
 
def step(x: int) -> int:
    s = 0
    while x:
        d = x % 10
        s += d * d
        x //= 10
    return s
 
def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    pos = 1
    out = []
    for _ in range(t):
        n = int(data[pos]); pos += 1
        cnt = Counter()
        for i in range(n):
            x = int(data[pos + i])
            for _ in range(100):
                x = step(x)
            cnt[x] += 1
        pos += n
        out.append(sum(c * (c - 1) // 2 for c in cnt.values()))
    print("\n".join(map(str, out)))
 
main()