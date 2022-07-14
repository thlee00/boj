#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> edges(10000);
int visited[10000] = { 0 };

void dfs(int v) {
	visited[v] = 1;
	cout << v << ' ';

	for (int i = 0; i < edges[v].size(); i++) {
		if (!visited[edges[v][i]])
			dfs(edges[v][i]);
	}

	return;
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < edges[x].size(); i++) {
			int y = edges[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for (int i = 0; i < m; i++) {
		sort(edges[i].begin(), edges[i].end());
	}

	dfs(v);
	cout << '\n';

	fill(visited, visited + 10000, 0);
	bfs(v);

	return 0;
}