#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;

    cin >> N >> M;

    vector<int> sum(N + 1, 0), result(M);

    for (int i = 1; i <= N; i++) {
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        result[i] = sum[b] - sum[a - 1];
    }

    for (int v : result) {
        cout << v << "\n";
    }

}
