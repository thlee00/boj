#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q;
	for (int i = 0; i < operations.size(); i++) {
		string temp = operations[i];
		if (temp[0] == 'I') {
			int num = stoi(temp.substr(2));
			q.push_back(num);
		}
		else if (temp[0] == 'D') {
			if (temp[2] == '1' && !q.empty()) {
				q.pop_back();
			}
			else if(!q.empty()) {
				q.erase(q.begin());
			}
		}
		sort(q.begin(), q.end());
	}
	if (!q.empty()) {
        	answer.push_back(q.back());
		answer.push_back(q.front());
	
	}
	else{
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}