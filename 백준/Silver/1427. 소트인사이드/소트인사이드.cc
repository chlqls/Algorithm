#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> cnt(11, 0);

    while (N > 0) {
        cnt[N % 10]++;
        N /= 10;
    }
    
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << i;
        }
    }
    
    return 0;
}