#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int one = 0;
    int second = 0;
    int l = A.size();
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    for(int i=0; i<l; i++)
        one += A[i] * B[i];
    
    sort(B.begin(), B.end());
    sort(A.begin(), A.end(), greater<>());
    
    for(int i=0; i<l; i++)
        second += A[i] * B[i];
    
    answer = max(one, second);
    
    return answer;
}