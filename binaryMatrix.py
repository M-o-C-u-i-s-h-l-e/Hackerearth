n, m = map(int, input().split())
data = [input() for _ in range(n)]
data = sorted(list(enumerate(data)), key = lambda x: int(x[1]), reverse = True)
print(data[0][0] + 1)
