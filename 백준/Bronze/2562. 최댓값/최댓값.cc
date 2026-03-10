#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, n = 0, max;

    vector<int> arr(9);

    for (int i = 0; i < 9; i++) {
        cin >> a;
        arr[i] = a;
    }

    max = arr[0];

    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            n = i;
        }
    }

    cout << max << endl;
    cout << n + 1;

}