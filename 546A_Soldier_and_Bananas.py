k, n, w = map(int, input().split())
cost = k * w * (w + 1) // 2
print(max(0, cost - n))