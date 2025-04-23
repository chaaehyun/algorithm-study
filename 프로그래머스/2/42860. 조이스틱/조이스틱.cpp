#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    
    for(int i = 0; i < length ; i++){
        char c = name[i];
        int minv = min(c - 65, 90 - c + 1);
        answer += minv;
    }
    
    int min_move = length - 1;
    
    for(int i = 0; i < length; i++){
        int next = i+1;
        
        while(next < length && name[next] == 65){
            next++;
        }
        
        int move = i + length - next + min(i, length - next);
        min_move = min(min_move, move);
    }
    
    answer+=min_move;
    
    return answer;
}