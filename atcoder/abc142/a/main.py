N = int(input())
if N % 2 == 1:
    print(f"{((N+1)/2)/N:.12f}")
else:
    print(f"{N/2/N:.12f}")
