from __future__ import print_function
import heapq

n, x = map(int, input().split())
a = list(map(int, input().split()))
b = []
for i in a:
    if i:
        heapq.heappush(b, -i)
    else:
        for _ in range(x):
            if len(b) > 0:
                heapq.heappop(b)
print(-sum(b))
