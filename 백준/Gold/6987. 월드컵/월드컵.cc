#include <iostream>
#include <vector>
using namespace std;

int in[6][3];
int pos[6][3];
int t1[15] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
int t2[15] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
int tot;
bool res[4];

void backtrack(int tc, int r) {
    if (res[tc]) return;

    if (r == 15) {
        if (tot != 30) return;

        bool valid = true;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (in[i][j] != pos[i][j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) res[tc] = true;
        return;
    }

    int a = t1[r], b = t2[r];

    // t1 wins, t2 loses
    pos[a][0]++; pos[b][2]++; tot += 2;
    backtrack(tc, r + 1);
    pos[a][0]--; pos[b][2]--; tot -= 2;

    // Draw
    pos[a][1]++; pos[b][1]++; tot += 2;
    backtrack(tc, r + 1);
    pos[a][1]--; pos[b][1]--; tot -= 2;

    // t1 loses, t2 wins
    pos[a][2]++; pos[b][0]++; tot += 2;
    backtrack(tc, r + 1);
    pos[a][2]--; pos[b][0]--; tot -= 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 0; tc < 4; tc++) {
        tot = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> in[i][j];
                pos[i][j] = 0;
            }
        }
        res[tc] = false;
        backtrack(tc, 0);
    }

    for (int tc = 0; tc < 4; tc++) {
        cout << (res[tc] ? 1 : 0);
        if (tc < 3) cout << " ";
    }
    cout << "\n";

    return 0;
}
