#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    while (!(pq.top() >= K)) {
        int first_min = pq.top();
        pq.pop();
        if (pq.empty())
            return -1;
        int second_min = pq.top();
        pq.pop();
        
        pq.push(first_min + 2 * second_min);
        
        answer++;
    }
    
    return answer;
}