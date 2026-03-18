#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str, msg;

    cin >> n;
    for (int i = 0; i < n; i++) {
        stack<char> s;
        msg = "YES";
        cin >> str;

        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                s.push(str[j]);
            }
            else {
                if (s.empty()) {
                    msg = "NO";
                    break;
                }
                else {
                    s.pop();
                }
            }
        }

        if (!s.empty()) {
            msg = "NO";
        }
        cout << msg << '\n';

    }

    return 0;
}