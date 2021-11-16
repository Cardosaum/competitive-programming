#!/usr/bin/env python
T, D, M = [int(x) for x in input().split()]
l = [0]
[l.append(int(input())) for _ in range(M)]
l.append(D)
if len(l) > 1:
    l = [j-i for i,j in zip(l[:-1], l[1:])]
if max(l) >= T and T <= D:
    print('Y')
else:
    print('N')
