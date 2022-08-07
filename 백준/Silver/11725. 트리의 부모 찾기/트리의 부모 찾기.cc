#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct {
	int par;
	vector<int> adj;
}node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	vector<node> nodes(100001);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		nodes[a].adj.push_back(b);
		nodes[b].adj.push_back(a);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < nodes[cur].adj.size(); i++) {
			int child = nodes[cur].adj[i];
			if (cur == 1 || (child != nodes[cur].par && nodes[cur].par != 0)) {
				nodes[child].par = cur;
				q.push(child);
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << nodes[i].par << '\n';


	return 0;
}