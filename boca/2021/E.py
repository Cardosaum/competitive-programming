#!/usr/bin/env python
from pprint import pprint as pp

N = int(input())
p = set()
for _ in range(N):
    p.add(tuple([int(x) for x in input().split()]))
p = sorted(p, key=lambda i: (i[1], i[0]))
# pp(p)


def merge_lr(d):
    if not d:
        return []
    intervals = []
    direction = d[0][1]
    # current_interval = [d[0][0], d[0][0] + 10]
    current_interval = [d[0][0], d[0][0] + 10, direction]
    for i in d:
        if i[0] >= current_interval[0] and i[0] <= current_interval[1] and i[
                1] == direction:
            current_interval[1] = i[0] + 10
        else:
            intervals.append(current_interval)
            direction = i[1]
            # current_interval = [i[0], i[0] + 10]
            current_interval = [i[0], i[0] + 10, direction]
    intervals.append(current_interval)
    return intervals


# print(f'merge_lr(p) = ')
# a = merge_lr(p)
# pp(a)
intervals = sorted(merge_lr(p))
# print('='*80)
# print('='*80)
# print('='*80)
# pp(intervals)

time = intervals[0][1]
if len(intervals) > 1:
    [time := max(time + 10, i[1]) for i in intervals[1:]]
print(time)
