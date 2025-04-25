#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int cnt = 0;
    int length = people.size();
    int left = 0;
    int right = length - 1;
    sort(people.begin(), people.end());
    
    if(people[0] + people[1] > limit)
        answer = length;
    else{
        while(left<=right){
            if(people[left] + people[right] <= limit){
                left++;
                right--;
            }else
                right--;
            
            answer++;
        }
    }

    return answer;
}