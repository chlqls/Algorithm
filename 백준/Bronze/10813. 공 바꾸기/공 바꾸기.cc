#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, b, n, m;

    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        swap(arr[a - 1], arr[b - 1]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}