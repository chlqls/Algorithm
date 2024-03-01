#include <iostream>

using namespace std;

//반복문을 이용한 방법
int gcdIter(int a, int b) {
    while(b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

//재귀를 이용한 방법
int gcdRecur(int a , int b) {
    //b == 0 -> a 리턴
    if(!b) {
        return a;
    }

    //b != 0 -> a에는 b, b에는 a % b 넣음
    return gcdRecur(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;

    if(a < b) {
        swap(a, b);
    }

    int gcd = gcdIter(a, b);
    //int gcd = gcdRecur(a, b);

    int lcm = a * b / gcd;

    cout << gcd << '\n' << lcm;
}
