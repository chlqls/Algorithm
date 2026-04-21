#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(vector<int> adj[], vector<bool> &visited, int R) {  // V : 정점 집합, E : 간선 집합, R : 시작 정점
    visited[R] = true;  // 시작 정점 R을 방문 했다고 표시한다.
    for (int next : adj[R]) {// E(R) : 정점 R의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
        if (!visited[next]) {
            dfs(adj, visited, next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, u, v, cnt = 0;
    cin >> N >> M;

    vector<int> adj[N + 1];
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            cnt++;
            dfs(adj, visited, i);
        }
    }

    dfs(adj, visited, 1);

    cout << cnt << '\n';

    return 0;
}