#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
long long ans = 0;

long long func(char* token) {
	long long res = 0;
	char* tok = strtok(token, "+");
	while (tok) {
		res += stoi(tok);
		tok = strtok(0, "+");
	}
	return res;
}

int main() {
	string str;
	vector<char *> tokens;
	cin >> str;
	char cstr[100];

	strcpy(cstr, str.c_str());
	char* tok = strtok(cstr, "-");

	while (tok) {
		tokens.push_back(tok);
		tok = strtok(0, "-");
	}
	ans += func(tokens[0]);
	for(int i = 1; i < tokens.size(); i++)
		ans -= func(tokens[i]);
	cout << ans;
	return 0;
}