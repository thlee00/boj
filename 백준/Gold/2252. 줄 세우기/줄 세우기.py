from collections import deque

n, m = map(int, input().split())

in_degree = [0 for i in range(n+1)]
edges = [[] for i in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    in_degree[b] += 1
    edges[a].append(b)

def topological_sort():
    res = []
    q = deque()

    for i in range(1, n+1):
        if in_degree[i] == 0:
            q.append(i)

    while q:
        cur = q.popleft()
        res.append(cur)

        for v in edges[cur]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)

    for i in res:
        print(i, ' ')

topological_sort()