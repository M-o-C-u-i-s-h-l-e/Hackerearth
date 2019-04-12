from __future__ import print_function

t = int(input())
while t:
	t -= 1
	ls, n = input().split()
	n = int(n)
	st = list(ls)
	times = 0
	for i in range(len(st) - n + 1):
		if (st[i] == '0'):
			for j in range(i, i+n):
				if st[j] == '0':
				    st[j] = '1'
				else:
				    st[j] = '0'
			times += 1
	flag = True
	for i in range(len(st)):
		if st[i] == '0':
			flag = False
			break
	if flag:
		print(times)
	else:
		print(-1)
        
