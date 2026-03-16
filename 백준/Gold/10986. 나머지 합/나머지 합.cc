#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a;
    long long sum = 0, result = 0;

    cin >> N >> M;

    vector<long long> remain(M, 0);

    for (int i = 1; i <= N; i++) {
        cin >> a;
        sum += a;
        remain[sum % M]++;
    }

    result += remain[0];

    for (int i = 0; i < M; i++) {
        result += remain[i] * (remain[i] - 1) / 2;
    }

    cout << result;

}