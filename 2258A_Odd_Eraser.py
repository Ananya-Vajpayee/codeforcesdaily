import sys
from math import gcd
 
def main():
    data = sys.stdin.read().split()
    t = int(data[0]); p = 1
    out = []
    for _ in range(t):
        n = int(data[p]); p += 1
        a = data[p:p + n]; p += n
        out.append(str(gcd(int(a[0]), int(a[-1]))))
    print("\n".join(out))
 
main()