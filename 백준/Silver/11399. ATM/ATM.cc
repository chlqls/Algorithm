#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, sum = 0;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i< N; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        sum += arr[i] * (N - i);
    }

    cout << sum << '\n';
    
    return 0;
}