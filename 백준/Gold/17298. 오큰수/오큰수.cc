#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n;

    stack<pair<int, int>> s;
    vector<int> v(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> x;

        while (!s.empty() && x > s.top().first) {
            v[s.top().second] = x;
            s.pop();
        }

        s.push({ x, i });
    }


    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';   
    }

    return 0;
}