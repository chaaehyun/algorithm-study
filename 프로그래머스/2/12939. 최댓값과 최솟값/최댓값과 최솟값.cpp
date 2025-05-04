#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    int maxv, minv;
    string temp = "";

    for (char ch : s) {
        if (ch != ' ') {
            temp += ch;
        } else {
            num.push_back(stoi(temp));
            temp = "";
        }
    }
    if (!temp.empty())
        num.push_back(stoi(temp));
    
    maxv = *max_element(num.begin(), num.end());
    minv = *min_element(num.begin(), num.end());
    
    answer += to_string(minv);
    answer += " ";
    answer += to_string(maxv);
        
    return answer;
}