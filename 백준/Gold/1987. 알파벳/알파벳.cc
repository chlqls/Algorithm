
#include <iostream>
#include <vector>

using namespace std;

int R, C, cnt = 0, MAX = 0;
char A[20][20];
bool visited[20][20];
bool ascii[26]; // 새로운 알파벳인지 확인용

void dfs(int x, int y) {
    visited[x][y] = true;
    
    char c = A[x][y];
    ascii[c - 'A'] = true;
    
    cnt++;
    if (cnt > MAX) {
        MAX = cnt;
    }

    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { 1, -1, 0, 0 };

    for(int i=0; i<4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];

        if (!visited[a][b] && !ascii[A[a][b] - 'A'] && a >= 0 && a < R && b >= 0 && b < C) {
            dfs(a, b);
        }
    }
    
    // 백트래킹, 값 되돌리는 과정
    cnt--;
    visited[x][y] = false;
    ascii[c - 'A'] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> s;

        for (int j = 0; j < C; j++) {
            A[i][j] = s[j];
        }
    }

    dfs(0, 0);

    cout << MAX << '\n';

    return 0;
}