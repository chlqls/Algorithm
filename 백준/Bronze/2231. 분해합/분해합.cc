#include <iostream>

using namespace std;

int bruteforce(int n) {
    for(int i = 1; i < n; i++) {
        int tmp = i;
        int sum = i;
        while(tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum == n) {
            return i;
        }
    }
    return 0;
}

int main() {

    //입력
    int n;
    cin >> n;

    //연산&출력
    cout << bruteforce(n);

    return 0;
}