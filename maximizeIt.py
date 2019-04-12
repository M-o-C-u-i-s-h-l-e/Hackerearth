from __future__ import print_function

def swap(ls):
    temp = ls[0]
    ls[0] = ls[1]
    ls[1] = temp
    return ls

n, k = int(input()), int(input())
ls = list()
for i in range(n):
	temp = list(map(int, input().split()))
	temp = swap(temp)
	ls.append(temp)
ls.sort()
ans = 0
arr = list()
for i in range(n):
	if ans + ls[i][0] <= k:
		arr.append(ls[i][1])
		ans += ls[i][0]
	else:
		break
if len(arr) > 0:
	arr.sort()
	for i in range(len(arr)):
		print(arr[i], end = "")
		if i < len(arr)-1:
			print(",", end = "")
else:
	print(-1)
