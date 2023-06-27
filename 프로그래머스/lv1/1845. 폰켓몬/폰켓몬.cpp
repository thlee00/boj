#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    set<int> pk_type;
    
    for (int i = 0; i < n; i++)
        pk_type.insert(nums[i]);
    
    answer = n / 2 < pk_type.size() ? n / 2 : pk_type.size();
    
    return answer;
}