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
    
    cur_time = jobs[0][0];
    disk.push(pii(jobs[0][0], jobs[0][1]));
    cur_idx++;
    
    while (!disk.empty()) {
        pii job = disk.top();
        disk.pop();
        cur_time += job.second;
        answer += cur_time - job.first;
        
        while (cur_idx < n) {
            if (jobs[cur_idx][0] <= cur_time) {
                disk.push(pii(jobs[cur_idx][0], jobs[cur_idx][1]));
                cur_idx++;
            }
            else
                break;
        }
        
        if (cur_idx < n && disk.empty()) {
            cur_time = jobs[cur_idx][0];
            disk.push(pii(jobs[cur_idx][0], jobs[cur_idx][1]));
            cur_idx++;
        }
    }
    
    return answer / n;
}