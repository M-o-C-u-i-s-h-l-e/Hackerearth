for _ in range(int(input())):
    n = int(input())
    ls = set()
    for i in range(n):
        n1, n2 = map(int, input().split())
        ls.add(n1)
        ls.add(n2)
    print(len(ls))
