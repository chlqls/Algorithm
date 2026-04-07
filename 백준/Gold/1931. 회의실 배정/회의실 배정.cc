#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, s, e;
    cin >> N;

    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        A[i] = {e, s}; // end start
    }

    sort(A.begin(), A.end());

    int end = A[0].first;
    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (A[i].second >= end) {
            end = A[i].first;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}