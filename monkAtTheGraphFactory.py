n = int(input())
ls = list(map(int, input().split()))
if sum(ls) / 2 == n - 1:
	print("Yes")
else:
	print("No")
