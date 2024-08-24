//프로그래머스 다리를 지나는 트럭
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int solution(int bridge_length, int weight, vector<int> truck_weights) {
//    int answer = 0;
//    queue<int> q;
//    int index = 0;
//    int sum = 0;
//    int car = 0;
//
//    while (1) {
//        if (index == truck_weights.size()) {
//            answer += bridge_length;
//            break;
//        }
//
//        answer+=1;
//        car = truck_weights[index];
//
//        if (sum + car <= weight) {
//            q.push(car);
//            sum += car;
//            index++;
//        }
//        else
//            q.push(0);
//
//        if (q.size() == bridge_length) {
//            sum -= q.front();
//            q.pop();
//        }
//    }
//    return answer;
//}