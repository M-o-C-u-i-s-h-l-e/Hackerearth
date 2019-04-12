n, m, k = map(int, input().split())
val = list(map(int, input().split()))
adj = [[] for _ in range(n)]
for _ in range(m):
	x, y = map(int, input().split())
	adj[x-1].append((val[y-1], y))
	adj[y-1].append((val[x-1], x))
for i in range(n):
	adj[i].sort(reverse = True)
for i in range(n):
	if len(adj[i]) < k:
		print(-1)
	else:
		print(adj[i][k-1][1])
