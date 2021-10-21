#!/usr/bin/env python

dp = {}

def f(n: int):
    if n in dp:
        return dp[n]

    if n <= 0:
        dp[n] = (1, 0)
    else:
        tmp = f(n-1)
        dp[n] = ((3*tmp[0])%1000000007 + tmp[1]%1000000007, tmp[0]%1000000007 + (3*tmp[1])%1000000007)
    return dp[n]

# [print(f'{n = }\n{f(n) = }\n\n') for n in range(200)]

# while (n := int(input().strip())) != 0:
#     print(f(n))

print(f(int(input().strip())))
