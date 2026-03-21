#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i = 0, num = 1;

    cin >> n;

    vector<char> ans(2 * n);

    stack<int> s;

    while (n--) {
        cin >> x;

        if (!s.empty() && x < s.top()) {
            cout << "NO" << '\n';
            return 0;
        }

        while (s.empty() || x != s.top()) {
            s.push(num++);
            ans[i++] = '+';
        }
        s.pop();
        ans[i++] = '-';

    }

    for (char v : ans) {
        cout << v << '\n';
    }

    return 0;
}