#!/usr/bin/env python

T = int(input().strip())
for _ in range(T):
    N, S = [int(i) for i in input().strip().split()]
    B = int(input().strip(), 2)
    if B % N:
        print('Phishing de criptomoeda.')
    else:
        print('To the moon!')
