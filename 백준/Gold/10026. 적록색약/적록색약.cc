#include <iostream>
#include <vector>

using namespace std;

int N;

void checkAdj(vector<vector<char>> A, vector<vector<bool>> &visited, int x, int y) {
    visited[x][y] = true;
    char c = A[x][y];

    if (y > 0 && A[x][y - 1] == c && !visited[x][y - 1]) { // 왼쪽
        checkAdj(A, visited, x, y - 1);
    }
    if (y < N - 1 && A[x][y + 1] == c && !visited[x][y + 1]) { // 오른쪽
        checkAdj(A, visited, x, y + 1);
    }
    if (x > 0 && A[x - 1][y] == c && !visited[x - 1][y]) { // 위
        checkAdj(A, visited, x - 1, y);
    }
    if (x < N - 1 && A[x + 1][y] == c && !visited[x + 1][y]) { // 아래
        checkAdj(A, visited, x + 1, y);
    }
}

void cntArea(vector<vector<char>> A) {
    int cnt = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (!visited[x][y]) {
                cnt++;
                checkAdj(A, visited, x, y);
            }
        }
    }

    cout << cnt << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    string s;

    cin >> N;

    vector<vector<char>> A(N, vector<char>(N));

    // 적록색약 아닌 사람
    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < N; j++) {
            A[i][j] = s[j];
        }
    }

    cntArea(A);
    
    
    // 적록색약
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 'G')
            A[i][j] = 'R';
        }
    }

    cntArea(A);

    return 0;
}