#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;

void warms(vector<vector<bool>> A, vector<vector<bool>> &visited, int x, int y) {
    visited[x][y] = true;

    if (y > 0 && A[x][y - 1] && !visited[x][y - 1]) { // 왼쪽
        warms(A, visited, x, y - 1);
    }
    if (y < M - 1 && A[x][y + 1] && !visited[x][y + 1]) { // 오른쪽
        warms(A, visited, x, y + 1);
    }
    if (x > 0 && A[x - 1][y] && !visited[x - 1][y]) { // 위
        warms(A, visited, x - 1, y);
    }
    if (x < N - 1 && A[x + 1][y] && !visited[x + 1][y]) { // 아래
        warms(A, visited, x + 1, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, K, X, Y;

    cin >> T;

    for(int i = 0; i < T; i++) {
        int cnt = 0;
        cin >> M >> N >> K;

        vector<vector<bool>> A(N, vector<bool>(M, false));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int j = 0; j < K; j++) {
            cin >> X >> Y;
            A[Y][X] = true;
        }

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (A[x][y] && !visited[x][y]) {
                    cnt++;
                    warms(A, visited, x, y);
                }
            }
        }
        cout << cnt << '\n';
    }


    return 0;
}