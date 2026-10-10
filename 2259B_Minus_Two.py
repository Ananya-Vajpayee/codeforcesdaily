import sys
def main():
    data = sys.stdin.read().split()
    t = int(data[0]); p = 1
    out = []
    for _ in range(t):
        n = int(data[p]); p += 1
        cnt = [0, 0, 0, 0]
        for i in range(n):
            cnt[int(data[p + i]) % 4] += 1
        p += n
        out.append(max(cnt[1] + cnt[3], cnt[0], cnt[2]))
    print("\n".join(map(str, out)))
main()