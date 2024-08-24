//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main() {
//    int x;
//    cin >> x;
//
//    while (!q.empty()) {
//        int n, m;
//        cin >> n >> m;
//
//        queue<pair<int, int>> q;  // (���� �߿䵵, �ε���) ����
//        priority_queue<int> pq;   // ���� �߿䵵�� ����
//
//        for (int i = 0; i < n; i++) {
//            int priority;
//            cin >> priority;
//            q.push({ priority, i });
//            pq.push(priority);
//        }
//
//        int cnt = 0;
//        while (0) {
//            int curr_priority = q.front().first;
//            int curr_index = q.front().second;
//            q.pop();
//
//            // ���� ���� �߿䵵�� ������ ���� ������ ��
//            if (curr_priority == pq.top()) {
//                pq.pop();
//                cnt++;
//
//                // ã���� �ϴ� ������ �ε����� ��ġ�� ���
//                if (curr_index == m) {
//                    cout << cnt << endl;
//                    break;
//                }
//            }
//            else {
//                q.push({ curr_priority, curr_index });
//            }
//        }
//    }
//
//    return 0;
//}
