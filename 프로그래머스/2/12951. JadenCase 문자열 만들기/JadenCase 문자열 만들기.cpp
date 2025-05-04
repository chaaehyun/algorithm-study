#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    
    for(char c : s){
        if(c!= ' '){
            temp+=c;
        }else{
            if(temp[0]>=97 && temp[0]<=122){
                temp[0] = temp[0]-32;
            }
            
            for(int i = 1; i<= temp.length(); i++){
                if(temp[i]>=65 && temp[i]<=90)
                    temp[i] = temp[i]+32;
            }
            
            answer += temp;
            answer += ' ';
            
            temp = "";
        }
    }
    
    if(temp != ""){
        if(temp[0]>=97 && temp[0]<=122)
            temp[0] = temp[0]-32;
        
        for(int i = 1; i<= temp.length(); i++){
                if(temp[i]>=65 && temp[i]<=90)
                    temp[i] = temp[i]+32;
            }
        
        answer+=temp;
    }
    
    return answer;
}