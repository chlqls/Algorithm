#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> count(42, 0);

    int a, result = 0;


    for (int i = 0; i < 10; i++) {
        cin >> a;
        count[a % 42]++;
    }

    for (int a : count) {
        if (a > 0) {
            result++;
        }
    }
    cout << result << endl;
}