#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    string input;
    map<string, int> name; //key: 이름, value: 번호
    map<int, string> num; //key: 번호, value: 이름
    
    //입력
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> input;
        name[input] = i;
        num[i] = input;
    }

    //출력
    while(m--) {
        cin >> input;
        if(isdigit(input[0])) { //입력이 숫자인 경우
            cout << num[stoi(input)] << '\n';
        }
        else { //입력이 문자인 경우
            cout << name[input] << '\n';
        }
    }

    return 0;
    
}