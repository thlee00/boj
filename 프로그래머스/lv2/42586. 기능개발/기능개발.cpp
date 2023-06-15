#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remaining_days;
    
    int n = progresses.size();
    
    for (int i = 0; i < n; i++) {
        int day = (100 - progresses[i]) / speeds[i];
        day += (100 - progresses[i]) % speeds[i] != 0;
        remaining_days.push_back(day);
    }
    
    int cur_num = 1;
    int cur_max_days = remaining_days[0];
    for (int i = 1; i < n; i++) {
        if (remaining_days[i] <= cur_max_days) {
            cur_num++;
        }
        else {
            answer.push_back(cur_num);
            cur_max_days = remaining_days[i];
            cur_num = 1;
        }
    }
    answer.push_back(cur_num);
    
    return answer;
}