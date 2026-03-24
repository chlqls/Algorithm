#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s, arrayStr;
        int n;
        deque<int> dq;
        bool isReversed = false, error = false;

        cin >> s;
        cin >> n;
        cin >> arrayStr;

        // [,,] 문자열 내의 숫자 -> dq에 저장하도록 문자열 처리
        string temp = "";
        for (int i = 0; i < arrayStr.length(); i++) {
            if (isdigit(arrayStr[i])) {
                temp += arrayStr[i]; // 숫자 형태의 문자를 계속 이어붙임 ('1', '0' -> "10")
            }
            else {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp)); // 숫자가 끝나면 정수로 변환해서 dq에 저장
                    temp = ""; // 초기화
                }
            }
        }

        // 함수 R, D 수행
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == 'R') {
                isReversed = !isReversed;
            }
            else {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (isReversed) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }

        // 에러 출력
        if (error) {
            cout << "error\n";
            continue;
        }

        // 결과 출력
        cout << '[';
        for (int i = 0; i < dq.size(); i++) {
            if (isReversed) {
                cout << dq.at(dq.size() - i - 1);
            }
            else {
                cout << dq.at(i);
            }
            if (i < dq.size() - 1) {
                cout << ',';
            }
        }
        cout << "]\n";
    }
    return 0;
}