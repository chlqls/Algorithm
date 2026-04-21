#include <iostream>
#include <vector>

using namespace std;

bool flag = false;
int cnt;

void dfs(vector<int> adj[], vector<bool> &visited, int R) {
    visited[R] = true;
    cnt++;
    
    if (cnt >= 5) {
        flag = true;
        return;
    }

    for (int next : adj[R]) {
        if (!flag && !visited[next]) {
            dfs(adj, visited, next);
        }
    }
    
    cnt--;
    visited[R] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, u, v;
    cin >> N >> M;

    vector<int> adj[N];

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        cnt = 0;

        dfs(adj, visited, i);

        if (flag) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}