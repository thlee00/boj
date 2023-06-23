#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct cmp {
    bool operator() (pii &a, pii &b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    priority_queue<pii, vector<pii>, cmp> disk;
    int cur_idx = 0;
    int cur_time = 0;
    
    sort(jobs.begin(), jobs.end());
    
    while (cur_idx < n || !disk.empty()) {
        while (cur_idx < n) {
            if (jobs[cur_idx][0] <= cur_time) {
                disk.push(pii(jobs[cur_idx][0], jobs[cur_idx][1]));
                cur_idx++;
            }
            else {
                if (disk.empty()) {
                    disk.push(pii(jobs[cur_idx][0], jobs[cur_idx][1]));
                    cur_time = jobs[cur_idx][0];
                    cur_idx++;
                }
                break;
            }
        }
        
        pii job = disk.top();
        disk.pop();
        cur_time += job.second;
        answer += cur_time - job.first;
    }
    
    answer /= n;
    return answer;
}