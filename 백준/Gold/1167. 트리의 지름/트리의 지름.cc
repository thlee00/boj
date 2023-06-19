#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

vector<pii> edges[100001];
bool visited[100001];
int maxNode = -1;
int maxDis = 0;

void dfs(int idx, int dis) {
	visited[idx] = true;

	if (maxDis < dis) {
		maxNode = idx;
		maxDis = dis;
	}
	
	for (int i = 0; i < edges[idx].size(); i++) {
		int v = edges[idx][i].first;
		if (!visited[v])
			dfs(v, dis + edges[idx][i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v_num;
	int res = 0;
	cin >> v_num;

	for (int i = 0; i < v_num; i++) {
		int s, v, d;
		cin >> s;
		
		while (cin >> v && v != -1) {
			cin >> d;
			edges[s - 1].push_back(pii(v - 1, d));
		}
	}

	dfs(0, 0);
	memset(visited, false, 100001);
	dfs(maxNode, 0);

	res = maxDis;

	cout << res;
	return 0;
}

/*
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
*/