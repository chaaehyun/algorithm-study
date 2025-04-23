#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int length = number.length();
    int cnt = 0;
    int memory = 0;
    stack<char> s;
    
    for(int i=0; i<length; i++){
        while(!s.empty() && s.top() < number[i]){
            s.pop();
            cnt++;
            
            if(cnt == k)
                break;
        }
        s.push(number[i]);
        
        if(cnt == k){
            memory = i;
            break;
        }
    }
    
    if(memory > 0){
        for(int i = memory + 1; i<length; i++)
            s.push(number[i]);
    }
    
    if (cnt < k) { // 완벽하게 내림차순 일 경우 농후.. 이땐 뒤에서부터 빼주면 된다
        while (cnt < k) {
            s.pop();
            cnt++;
        }
    }
    
    string opposite = "";
    
    while(!s.empty()){
        char c = s.top();
        s.pop();
        opposite += c;
    }
    
    for(int i = opposite.length() - 1; i>=0 && answer.length() < length - k; i--){ // answer.length() <= length - k의 위험성
        answer += opposite[i];
    }
    
    return answer;
}