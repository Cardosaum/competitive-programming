N, K = [int(i) for i in input().split()]
friends = [i for i in input().split() if int(i) >= K]
print(len(friends))
