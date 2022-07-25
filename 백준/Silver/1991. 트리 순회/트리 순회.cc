#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct {
	char left;
	char right;
} node;

map<char, node> list;

void preorder(char root) {
	node cur = list[root];
	cout << root;
	if (cur.left != '.')
		preorder(cur.left);
	if (cur.right != '.')
		preorder(cur.right);
	return;
}

void inorder(char root) {
	node cur = list[root];
	if (cur.left != '.')
		inorder(cur.left);
	cout << root;
	if (cur.right != '.')
		inorder(cur.right);
	return;
}

void postorder(char root) {
	node cur = list[root];
	if (cur.left != '.')
		postorder(cur.left);
	if (cur.right != '.')
		postorder(cur.right);
	cout << root;
	return;
}

int main() {
	int n, rt;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char nd;
		node temp;
		cin >> nd >> temp.left >> temp.right;
		list[nd] = temp;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;

}