#!/usr/bin/env python
N, K = [int(i) for i in input().split()]
sequence = []
colors = {}
numbers = []
final = []
for i in range(N):
    number, color = [int(i) for i in input().split()]
    sequence.append(color)
    numbers.append(number)
    colors.setdefault(color, [])
    colors[color].append(number)
numbers.sort()
colors = {k: sorted(v, reverse=True) for k,v in colors.items()}

for i in sequence:
    final.append(colors[i].pop())
if final == numbers:
    print('Y')
else:
    print('N')


