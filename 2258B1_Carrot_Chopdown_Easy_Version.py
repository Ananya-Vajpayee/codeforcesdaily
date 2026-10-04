import sys
 
def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    def nxt():
        nonlocal idx
        v = data[idx]; idx += 1
        return v
 
    t = int(nxt())
    out = []
    for _ in range(t):
        n = int(nxt()); m = int(nxt())
        cnt = [0] * (m + 1)
        for _ in range(n):
            v = int(nxt())
            cnt[v] += 1
 
        best = 0
        prefix = 0
        for x in range(1, m + 1):
            prefix += cnt[x]
            suffix = n - prefix  # number of a_i > x
            bonus = cnt[2 * x] if 2 * x <= m else 0
            g = cnt[x] + suffix + bonus
            if g > best:
                best = g
        out.append(str(best))
 
    print("\n".join(out))
 
if __name__ == "__main__":
    main()