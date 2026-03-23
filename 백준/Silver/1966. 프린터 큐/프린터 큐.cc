#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, N, M;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> N >> M;

        int target, result = 0;
        queue<pair<int, int>> q;
        vector<int> cnt(9, 0);

        for (int j = 0; j < N; j++) {
            cin >> x;
            q.push({ x, j });
            cnt[x - 1]++;
            if (j == M) {
                target = x;
            }
        }

        for (int j = 9; j >= target; j--) {
            int c = cnt[j - 1];
            while (c) {
                if (q.front().first == j) {
                    c--;
                    result++;
                    if (j == target && q.front().second == M) {
                        break;
                    }
                    q.pop();
                }
                else {
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        
        cout << result << '\n';
    }

    return 0;
}