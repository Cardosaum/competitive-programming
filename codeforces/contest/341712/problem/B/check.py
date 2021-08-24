#!/usr/bin/env python3

from math import gcd

with open('ans') as a, open('test.in') as t:
    ok = a.read().strip().splitlines()
    sa = [list(map(len, x.strip().split())) for x in ok]
    st = [list(map(int, x.strip().split())) for x in t.read().strip().splitlines()[1:]]
    for x,y,z in zip(st,sa,ok):
        z = [int(x.strip()) for x in z.strip().split()]
        z.append(gcd(*z))
        z.append(len(str(gcd(*z))))
        if x[0] != y[0] or x[1] != y[1] or x[2] != z[3]:
        # if x[2] != z[3]:
            print(x,y,z)
    # print(len(st), len(sa))
    # print(st, sa)
