#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	set<int> s;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		if (s.find(b) != s.end())
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}