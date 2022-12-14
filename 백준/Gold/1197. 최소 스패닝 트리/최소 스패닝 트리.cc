#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int find_root(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find_root(parent[a]);
}

void union_root(int a, int b) {
	a = find_root(a);
	b = find_root(b);

	if (a != b)
		parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, res = 0, cnt = 0;
	cin >> v >> e;

	vector<pair<pair<int, int>, int>> edge;

	for (int i = 0; i < v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edge.push_back(make_pair(make_pair(a, b), c));
	}

	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < e; i++) {
		int a = edge[i].first.first;
		int b = edge[i].first.second;

		if (find_root(a) != find_root(b)) {
			union_root(a, b);
			res += edge[i].second;
		}
	}

	cout << res;

	return 0;
}