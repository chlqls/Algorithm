#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + M);

    for (int i = 0; i < N + M; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int v : arr) {
        cout << v << ' ';
    }

    return 0;
}