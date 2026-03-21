#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, h;

    cin >> n;

    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++) {
        cin >> x;

        // x보다 큰 수가 top에 올 때까지 pop
        while (!s.empty() && x > s.top().first) {
            s.pop();
        }

        // pop 하고 스택이 비어있으면 0 출력
        if (s.empty()) {
            cout << 0 << ' ';
        }
        else {
            cout << s.top().second << ' ';
        }

        s.push({x, i + 1});
    }

    return 0;
}