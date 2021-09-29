#!/usr/bin/env python

I = int(input().strip())
infractions = {}
for _ in range(I):
    p, a = [int(x) for x in input().strip().split()]
    infractions.setdefault(p, {a: 0})
    if a in infractions[p]:
        infractions[p][a] += 1
    else:
        infractions[p] |= {a: 1}
M = [int(i) for i in [x for x in input().strip() if x.isdigit()]][0]
_ = input()
for _ in range(M):
    n = int(input().strip())
    if n not in infractions:
        print(f'Grato, cidadao {n}.')
    else:
        print(f'Teje preso, {n}!')
        for k,v in {k: v for k, v in sorted(infractions[n].items(), key=lambda i: (i[1], -i[0]), reverse=True)}.items():
            print(f'- Art. {k}: {v} ocorrencia(s).')
