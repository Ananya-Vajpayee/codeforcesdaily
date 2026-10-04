import sys
from collections import Counter
 
def main():
    input_data = sys.stdin.read().split()
    idx = 0
    t = int(input_data[idx]); idx += 1
    results = []
    for _ in range(t):
        n = int(input_data[idx]); idx += 1
        a = list(map(int, input_data[idx:idx + n])); idx += n
        
        cnt = Counter(a)
        # find the value with max frequency
        X, F = max(cnt.items(), key=lambda kv: kv[1])
        O = n - F
        
        total_others = sum(a) - X * F
        played_X = min(F, O + 2)
        
        ans = total_others + X * played_X
        results.append(str(ans))
    
    print('\n'.join(results))
 
main()