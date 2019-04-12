n = int(input())
arr = [int(input()) for _ in range(n+1)]
temp = arr.copy()
temp.sort(reverse = True)
dict = {}
ans = []
for i in range(n+1):
	if temp[i] not in dict.keys():
		v = temp.copy()
		v.pop(i)
		flag = True
		for j in range(n):
			Sum = s1 = 0
			for k in range(j+1):
				Sum += v[k]
			for k in range(j+1, n):
				s1 += min(j+1, v[k])
			if Sum > (j+1) * j + s1:
				flag = False
				break
			if j == n-1 and Sum % 2 == 1:
				flag = False
				break
		dict[temp[i]] = flag
for i in range(n+1):
	if dict[arr[i]]:
		ans.append(i+1)
print(len(ans))
for i in ans:
	print(i)
