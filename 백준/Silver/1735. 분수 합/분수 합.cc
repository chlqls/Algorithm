#include <iostream>

using namespace std;

int gcdIter(int a, int b) {
    if(a < b) {
        swap(a, b);
    }

    while(b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int a, b, c, d, e, f;
    cin >> a >> b;
    cin >> c >> d;

    e = a * d + c * b; //더한 후 분자
    f = b * d; // 더한 후 분모(두 분모를 곱해서 통분)
    
    //분자와 분모의 최대공약수를 찾아 약분
    int gcd = gcdIter(e, f);
    
    e /= gcd;
    f /= gcd;

    cout << e << ' ' << f;
}