#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    map<int, int> m;
    
    for(int i=0; i<n; i++)
        m[nums[i]]++;
    
    answer = min((int)m.size(), n/2);
    
    return answer;
}