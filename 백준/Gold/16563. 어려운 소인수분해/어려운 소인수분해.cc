#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 5000000;

void getPrime(vector<int> &prime) {
    for(int i = 2; i * i <= MAX_SIZE; i++) {
        if(prime[i]) {
            continue;
        }
        for(int j = i * i; j <= MAX_SIZE; j += i) {
            if(prime[j]) {
                continue;
            }
            prime[j] = i;
        }
    }
}


vector<int> getPrimeFactor(int n, int k, vector<int> &prime) {
    vector<int> ans;
    while(prime[k]) {
        ans.push_back(prime[k]);
        k /= prime[k];
    }
    ans.push_back(k);
    return ans;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> prime(MAX_SIZE + 1, 0);

    getPrime(prime);

    while(n--) {
        int k;
        cin >> k;
        vector<int> ans = getPrimeFactor(n, k, prime);

        for(int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}
