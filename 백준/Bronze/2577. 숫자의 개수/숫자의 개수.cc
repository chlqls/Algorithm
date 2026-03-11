#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> count(10, 0);

    int a, b, c, n;

    cin >> a >> b >> c;

    n = a * b * c;

    while (n > 0) {
        count[n % 10]++;
        n = n / 10;
    }

    for (int v : count) {
        cout << v << endl;
    }
    
}