import sys
 
def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    pos = 1
    out = []
    for _ in range(t):
        n = int(data[pos])
        a = list(map(int, data[pos + 1:pos + 4]))
        pos += 4
        out.append(max(n - x for x in a))
    print("\n".join(map(str, out)))
 
main()