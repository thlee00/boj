#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[1001];
int in_degree[1001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		
		int u;
		cin >> u;
		num--;
		
		while (num--) {
			int v;
			cin >> v;
			edge[u].push_back(v);
			in_degree[v]++;
			u = v;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0)
			q.push(i);
	}


	vector<int> res;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);

		for (int i = 0; i < edge[cur].size(); i++) {
			int v = edge[cur][i];
			in_degree[v]--;
			if (in_degree[v] == 0)
				q.push(v);
		}
	}

	if (res.size() != n)
		cout << 0;
	else {
		for (int i = 0; i < res.size() - 1; i++)
			cout << res[i] << '\n';
		cout << res[res.size() - 1];
	}

	return 0;
}