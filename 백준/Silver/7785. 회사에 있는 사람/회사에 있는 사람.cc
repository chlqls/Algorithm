#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    string input, state;
    set<string> s;

    //입력&연산
    cin >> n;
    while(n--) {
        cin >> input >> state;
        if(state == "enter") {
            s.insert(input);
        }
        else {
            s.erase(input);
        }
    }
    //출력
    for (auto iter = s.rbegin(); iter != s.rend(); iter++) { //이름을 사전 순의 역순으로
        cout << *iter << '\n';
    }

    return 0;
    
}