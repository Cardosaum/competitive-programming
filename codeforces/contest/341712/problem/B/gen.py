#!/usr/bin/env python3

import random

with open('test.in', 'w') as f:
    f.write(f'285\n')
    for i in range(285):
        a = random.randint(1,9)
        b = random.randint(1,9)
        c = random.randint(1, min(a,b))
        f.writelines(' '.join([str(x) for x in [a, b, c]]) + '\n')
