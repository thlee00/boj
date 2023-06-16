#include <string>
#include <vector>
#include <deque>

using namespace std;

typedef struct {
    int loc;
    int prior;
} process;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    deque<process> processes;
    
    for (int i = 0; i < n; i++) {
        process temp;
        temp.loc = i;
        temp.prior = priorities[i];
        processes.push_back(temp);
    }
    
    while (!processes.empty()) {
        process cur = processes.front();
        processes.pop_front();
        bool check = true;
        for (int i = 0; i < processes.size(); i++) {
            if (cur.prior < processes[i].prior) {
                check = false;
                processes.push_back(cur);
                break;
            }
        }
        if (check) {
            answer++;
            if (cur.loc == location) {
                break;
            }
        }
    }
    
    return answer;
}