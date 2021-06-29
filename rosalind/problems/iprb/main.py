#!/usr/bin/env python

k, m, n = [int(x) for x in input().strip().split()]
p = k+m+n
print(
    ( (4*k*(k-1)) + (3*m*(m-1)) + (4*(2*k*m + 2*k*n + m*n)) ) / 4*p*(p-1)
)
