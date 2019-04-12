n = int(input())
ls = list(map(int, input().split()))
ans = 1e18
for i in range(n):
	temp = 0
	for j in range(n):
		temp += min(abs(ls[i] - ls[j]), ls[j])
	ans = min(ans, temp)
print(ans)
