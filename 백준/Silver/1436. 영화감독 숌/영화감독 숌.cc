#include <iostream>

using namespace std;

int getTitle(int n) {
    int title = 666, cnt = 1, tmp;
    while(cnt != n) {
        title++;
        tmp = title;
        while(tmp >= 666) {
            if(tmp % 1000 == 666) {
                cnt++;
                break;
            }
            tmp /= 10;
        }
    }
    return title;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n;
    cin >> n;

    //연산&출력
    cout << getTitle(n);

    return 0;
}