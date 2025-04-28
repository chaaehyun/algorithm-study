#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string, int> playCount;
    
    for(int i=0; i<genres.size(); i++){
        string genre = genres[i];
        int cnt = plays[i];
        playCount[genre] += cnt;
    }
    
    vector<pair<string, int>> vec (playCount.begin(), playCount.end());
    
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    
    
    int cnt = 0;
    while(cnt <= vec.size()){
        vector<pair<int, int>> playlist;
        
        for(int i=0; i<genres.size(); i++){
            if(vec[cnt].first == genres[i]){
                playlist.push_back({plays[i], i});
            }
        }
        
        sort(playlist.begin(), playlist.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
        
        for(int i=0;i<playlist.size() && i<2;i++){
            answer.push_back(playlist[i].second);
        }
        cnt++;
    }

    return answer;
}