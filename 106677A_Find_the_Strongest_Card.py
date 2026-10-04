import sys
 
def main():
    data = sys.stdin.read().split()
    idx = 0
 
    # Strength order from strongest to weakest in the "big two" ranking
    order = [2, 1, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3]
    strength = {rank: pos for pos, rank in enumerate(order)}
 
    out = []
    while True:
        n = int(data[idx]); idx += 1
        if n == 0:
            break
        cards = [int(data[idx + i]) for i in range(n)]
        idx += n
        # smallest 'position' in order = strongest card
        strongest = min(cards, key=lambda r: strength[r])
        out.append(str(strongest))
 
    print("\n".join(out))
 
if __name__ == "__main__":
    main()