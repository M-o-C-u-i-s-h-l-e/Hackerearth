from __future__ import print_function

t = int(input())
while t:
	t -= 1
	n, c = map(int, input().split())
	ls = list(map(int, input().split()))
	ls.sort()
	Count = 0
	for i in ls:
		if c - i >= 0:
			c -= i;
			Count += 1
		else:
			break
	print(Count)
