#include <iostream>
#include <vector>

using namespace std;

void calculator(string order, int x, vector<bool> &s) {
    if(order == "add") {
        s[x] = true;
    }
    else if(order == "remove") {
        s[x] = false;
    }
    else if(order == "toggle") {
        if(s[x] == true) {
            s[x] = false;
        } else {
            s[x] = true;;
        }
    }
}

int check(int x, vector<bool> &s) {
    if(s[x] == true) {
        return 1;
    } else {
        return 0;
    }
}

void changeAll(vector<bool> &s, bool b) {
    for(int i = 1; i < s.size(); i++) {
        s[i] = b;
    }
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int m;
    cin >> m;

    string order;
    int x = 0;
    vector<bool> s(21, false);

    //연산&출력
    while(m--) {
        cin >> order;
        if(order == "all") {
            changeAll(s, true);
        } else if(order == "empty") {
            changeAll(s, false);
        }
        else {
            cin >> x;
            if(order == "check") {
                cout << check(x, s) << '\n';
            }
            else {
                calculator(order, x, s);
            }
        }
    }
    return 0;
}