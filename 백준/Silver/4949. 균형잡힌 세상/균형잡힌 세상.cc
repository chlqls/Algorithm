#include <iostream>
#include <stack>
#include <string>

using namespace std;

void check_balance(string str) {
    stack<char> s;
    bool check = true;
            for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } 
            if(str[i] == ')') {
                if(!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
            else if(str[i] == ']') {
                if(!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
        }

        //출력
        if(check && s.empty()) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }

}

int main() {
    while(true) {
        string input;

        //한줄씩 입력
        getline(cin, input);

        //입력의 종료조건 확인
        if(input.length() == 1 && input == ".") {
            break;
        }

        check_balance(input);
    }
}