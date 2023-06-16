#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int n = truck_weights.size();
    int cur_weights = 0;
    int cur_idx = 0;
    queue<int> bridge;
    
    while (cur_idx < n) {
        int temp = truck_weights[cur_idx];
        if (temp + cur_weights <= weight) {
            bridge.push(temp);
            cur_weights += temp;
            cur_idx++;
        }
        else {
            bridge.push(-1);
        }
        if (bridge.size() == bridge_length) {
            int truck = bridge.front();
            if (truck != -1)
                cur_weights -= truck;
            bridge.pop();
        }
        answer++;
    }
    
    answer += bridge_length;
    
    return answer;
}