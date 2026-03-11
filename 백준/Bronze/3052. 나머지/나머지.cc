#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N = 10;

    int a, total = 10;

    vector<int> arr(N);
    vector<int> remain(N, 0);

    for (int i = 0; i < arr.size(); i++) {
        cin >> a;
        arr[i] = a;
        remain[i] = arr[i] % 42;
    }

    for (int i = 0; i < remain.size(); i++) {
        for (int j = i + 1; j < remain.size(); j++) {
            if (remain[i] == remain[j]) {
                total--;
                break;
            }
        }
    }

    cout << total;
}