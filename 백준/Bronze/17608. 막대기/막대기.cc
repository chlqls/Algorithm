#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, cnt = 0, max = 0;
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        s.push(h);
    }

    for(int i = 0; i < n; i++) {
        if (s.top() > max) {
            cnt++;
            max = s.top();
        }
        s.pop();
    }

    cout << cnt << '\n';
}