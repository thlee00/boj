#include <iostream>
#include <set>
#include <string>

using namespace std;
set<string> a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		a.insert(str);
	}

	for (int i = 0; i < m; i++) {
		string check;
		cin >> check;
		if (a.find(check) != a.end())
			ans++;
	}

	cout << ans;

	return 0;
}