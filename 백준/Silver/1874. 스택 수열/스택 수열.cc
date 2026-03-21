#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, num = 1;

    cin >> n;

    vector<char> ans;

    stack<int> s;

    while (n--) {
        cin >> x;

        while (num <= x) {
            s.push(num++);
            ans.push_back('+');
        }

        if (x == s.top()) {
            s.pop();
            ans.push_back('-');
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    for (char v : ans) {
        cout << v << '\n';
    }

    return 0;
}