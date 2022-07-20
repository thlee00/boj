#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, string> password;

	while (n--) {
		string addr, pass;
		cin >> addr >> pass;
		password[addr] = pass;
	}
	while (m--) {
		string addr;
		cin >> addr;
		cout << password[addr] << endl;
	}
	return 0;
}