import sys
from collections import Counter
 
def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    pos = 1
    out = []
    for _ in range(t):
        n = int(data[pos]); pos += 1
        a = list(map(int, data[pos:pos + n])); pos += n
 
        cnt = Counter(a)
        values = sorted(cnt, reverse=True)   # distinct values, descending
        res = []
        for level in range(1, max(cnt.values()) + 1):
            for v in values:
                if cnt[v] >= level:
                    res.append(v)
        out.append(" ".join(map(str, res)))
    print("\n".join(out))
 
main()