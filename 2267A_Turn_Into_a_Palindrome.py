import sys
 
def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    pos = 1
    out = []
    for _ in range(t):
        n = int(data[pos]); c = data[pos + 1]; s = data[pos + 2]
        pos += 3
 
        coins = 0
        for i in range(n // 2):
            x, y = s[i], s[n - 1 - i]
            if x == y:
                continue
            coins += 1 if (x == c or y == c) else 2
        out.append(coins)
    print("\n".join(map(str, out)))
 
main()