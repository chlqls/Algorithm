#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void isPrime(int n, vector<bool> &is_prime) { //n보다 작은 모든 소수 찾기
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= sqrt(n); i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> is_prime(1000001, true);
    isPrime(1000001, is_prime);

    while(true) {
        int n;
        cin >> n;
        if(!n) {
            break;
        }

        bool flag = true;
        for(int i = 3; i < n; i += 2) { //홀수만 확인해도 됨
            int a = i;
            int b = n - a;

            if(is_prime[a] && is_prime[b]) { //a와 b 모두 소수인지 확인
                cout << n << " = " << a << " + " << b << '\n';
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }   
}
