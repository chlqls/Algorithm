#include <iostream>
#include <vector>

using namespace std;

bool checkDuplication(int arrow, char alphabet, vector<char> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        if(i != arrow && arr[i] == alphabet) {
            return true;
        }
    }
    return false;
}

int findWheel(int n, int k, vector<char> &arr) {
    int arrow = 0;

    while(k--) {
        int s;
        char alphabet;
        cin >> s >> alphabet;

        arrow = (arrow + s) % n;

        //해당 인덱스에 이미 다른 값이 저장되어있거나, 같은 글자가 저장되는 경우 예외처리
        if((arr[arrow] != '?' && arr[arrow] != alphabet) || checkDuplication(arrow, alphabet, arr)) { 
            arrow = -1;
            break;
        }
        
        arr[arrow] = alphabet;
    }
    return arrow;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, k;
    cin >> n >> k;

    vector<char> arr(n, '?');

    int arrow = findWheel(n, k, arr);

    if(arrow == -1) { //arrow가 -1이면 해당하는 행운의 바퀴가 없으므로 '!' 출력
        cout << '!';
    }
    else {
        //출력(마지막으로 화살표가 가리키는 문자부터 시계방향으로 알파벳 출력)
        for(int i = arrow; i >= 0; i--) {
            cout << arr[i];
        }
        for(int i = arr.size() - 1; i > arrow; i--) {
            cout << arr[i];
        }
    }
}