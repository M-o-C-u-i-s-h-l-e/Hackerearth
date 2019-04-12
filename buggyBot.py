n, m, k = map(int, input().split())
graph = [set() for _ in range(n+1)]
ans = set()
temp = [set() for _ in range(n+1)]
ia, ib, pos = [0]*k, [0]*k, [0]*(k+1)
for i in range(m):
	a, b = map(int, input().split())
	graph[a].add(b)
for i in range(k):
	ia[i], ib[i] = map(int, input().split())
pos[0] = 1
cp = 1
for i in range(k):
	if cp == ia[i]:
		cp = ib[i]
	pos[i+1] = cp
ee = [i for i in range(n+1)]
ans.add(pos[k])
for i in range(k-1, -2, -1):
	cnode = pos[i+1]
	for j in graph[cnode]:
		ans.add(ee[j])
		temp[j].add(cnode)
	graph[cnode].clear()
	if i >= 0:
		ee[ia[i]] = ee[ib[i]]
		for j in temp[ia[i]]:
			graph[j].add(ia[i])
		temp[ia[i]].clear()
res = sorted(list(ans))
print(len(res))
for i in res:
	print(i, end = " ")
print()
