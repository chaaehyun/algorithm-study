// น้มุ 9012น๘ ฐýศฃ

//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//int n;
//
//int main() {
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		queue<char> q;
//		int flag = 0;
//		string order;
//		cin >> order;
//
//		for (int j = 0; j < order.length(); j++) {
//			if (q.empty() && order[j] == ')') {
//				flag = 0;
//				break;
//				}
//			else if(order[j]=='(') {
//				q.push(order[j]);
//			}
//			else {
//				q.pop();
//			}
//			
//			flag = 1;
//		}
//
//		if (!q.empty())
//			flag = 0;
//		
//		if (flag == 1)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	
//	return 0;
//}