#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, a_b, a_c, b_a, b_c, c_a, c_b;

    cin >> N;

    vector<int> boy(3, 0), girl(3, 0);

    for (int i = 0; i < 3; i++) {
        cin >> boy[i] >> girl[i];
    }

    for (int i = 0; i < boy[0]; i++) {
        a_b = i;
        a_c = boy[0] - a_b;
        b_c = girl[2] - a_c;
        b_a = boy[1] - b_c;
        c_a = girl[0] - b_a;
        c_b = boy[2] - c_a;

        if (a_b >= 0 && a_c >= 0 && b_a >= 0 && b_c >= 0 && c_a >= 0 && c_b >= 0 && (girl[1] == a_b + c_b)) {
            cout << 1 << '\n';
            cout << a_b << ' ' << a_c << '\n';
            cout << b_a << ' ' << b_c << '\n';
            cout << c_a << ' ' << c_b << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}