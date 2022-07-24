#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> input;
bool visited[9];
int ans[9];
int n, m;

void func(int idx) {
	//현재 idx개까지 선택한 상황
	//m개 다 뽑은 경우
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	//m개 다 못 뽑은 경우
	//방문하지 않은 원소에 대해서 선택하거나 선택하지 않거나
	for (int i = 0; i < input.size(); i++) {
		if (visited[i])
			continue;

		//현재 원소 선택하는 경우
		visited[i] = true;
		ans[idx] = input[i];
		func(idx + 1);

		//현재 원소 선택하지 않는 경우
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	input.resize(n);

	for (int i = 0; i < n; i++)
		cin >> input[i];

	sort(input.begin(), input.end());

	func(0);

	return 0;
}