from pprint import pprint
import itertools

n,m,k = [int(x) for x in input().split()]
chips = []
targets = []
for i in range(k):
    chips.append([int(x) for x in input().split()])
for i in range(k):
    targets.append([int(x) for x in input().split()])

def walk(chips, targets):
    print(f"{list(zip(chips, targets)) = }")
    # print(f"{chips = }")
    # print(f"{targets = }")
    # for i in zip(chips, targets):
    #     print(i)

pprint(chips)
pprint(targets)


print()
for i in itertools.permutations(list(range(len(chips)))):
    print(f"{i = }")
    # walk(c,t)

