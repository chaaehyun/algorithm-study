// 백준 1966번 프린터 큐

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int x;
    cin >> x;

    while (x--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;  // (문서 중요도, 인덱스) 저장
        priority_queue<int> pq;   // 문서 중요도만 저장

        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            q.push({ priority, i });
            pq.push(priority);
        }

        int cnt = 0;
        while (!q.empty()) {
            int curr_priority = q.front().first;
            int curr_index = q.front().second;
            q.pop();

            // 가장 높은 중요도의 문서와 현재 문서를 비교
            if (curr_priority == pq.top()) {
                pq.pop();
                cnt++;

                // 찾고자 하는 문서의 인덱스와 일치할 경우
                if (curr_index == m) {
                    cout << cnt << endl;
                    break;
                }
            }
            else {
                q.push({ curr_priority, curr_index });
            }
        }
    }

    return 0;
}
