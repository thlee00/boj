#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int n;
int in[100001];
int post[100001];
int in_idx[100001];

void preorder(int inbegin, int inend, int postbegin, int postend) {
	if (inbegin > inend || postbegin > postend)
		return;

	cout << post[postend] << ' ';
	int root_idx = in_idx[post[postend]];
	int left_num = root_idx - inbegin;

	preorder(inbegin, root_idx - 1, postbegin, postbegin + left_num - 1);
	preorder(root_idx + 1, inend, postbegin + left_num, postend - 1);

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> in[i];
		in_idx[in[i]] = i;
	}

	for (int i = 1; i <= n; i++)
		cin >> post[i];

	preorder(1, n, 1, n);

	return 0;
}