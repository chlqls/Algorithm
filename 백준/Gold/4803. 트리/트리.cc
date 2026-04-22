#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> adj[], vector<bool>& visited, int curr, int prev) {
    visited[curr] = true;
    bool isTree = true;

    for (int next : adj[curr]) {
        if (next == prev) continue; // 부모로 되돌아가는 것은 무시

        if (visited[next]) {
            // 부모가 아닌데 이미 방문했다면 -> 사이클 발견
            isTree = false;
        } else {
            // 자식 노드의 탐색 결과 중 하나라도 사이클이 있으면 이 연결 요소는 트리가 아님
            if (!dfs(adj, visited, next, curr)) {
                isTree = false;
            }
        }
    }
    return isTree;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int idx = 1;

    while (idx) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        vector<int> adj[n + 1];

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "Case " << idx++ ;

        int cnt = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, i, 0)) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            cout << ": No trees.\n";
        }
        else if (cnt == 1) {
            cout << ": There is one tree.\n";
        }
        else {
            cout << ": A forest of " << cnt << " trees.\n";
        }
    }

    return 0;
}