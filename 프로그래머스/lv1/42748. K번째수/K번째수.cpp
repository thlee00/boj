#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int idx = 0; idx < commands.size(); idx++) {
        int i = commands[idx][0] - 1;
        int j = commands[idx][1] - 1;
        int k = commands[idx][2] - 1;
        
        vector<int> cur_array(array.begin() + i, array.begin() + j + 1);
        sort(cur_array.begin(), cur_array.end());
        answer.push_back(cur_array[k]);
    }
    
    return answer;
}