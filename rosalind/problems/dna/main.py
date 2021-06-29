#!/usr/bin/env python

from sys import stdin
from pprint import pprint
s = stdin.read().strip()
d = {}
for i in s:
    d.setdefault(i, 0)
    d[i] += 1
for k,v in sorted(d.items()):
    print(v, end=" ")
print()
