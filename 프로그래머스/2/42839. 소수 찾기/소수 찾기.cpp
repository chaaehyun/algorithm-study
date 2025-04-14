#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int isPrime(int num){
    if(num<2)
        return false;
    
    for(int i=2; i<=sqrt(num); i++)
        if(num%i==0)
            return false;
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int>ans{};
    
    sort(numbers.begin(), numbers.end());
    
    do{
        string num;
        for(int i=0;i<numbers.size();i++){
            num+=numbers[i];
            if(isPrime(stoi(num)))
                ans.insert(stoi(num));
            
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = ans.size();
    return answer;
}