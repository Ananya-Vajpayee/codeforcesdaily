t = int(input())
 
while t:
    t -= 1
 
    n, m = map(int, input().split())
 
    available = set()
 
    # Store first letters of ordinary words
    for _ in range(n):
        word = input()
        available.add(word[0].upper())
 
    ans = "YES"
 
    # Check abbreviations
    for _ in range(m):
        abbr = input()
 
        for ch in abbr:
            if ch not in available:
                ans = "NO"
 
    print(ans)