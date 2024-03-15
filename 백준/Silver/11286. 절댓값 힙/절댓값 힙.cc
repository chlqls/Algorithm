#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const int& x1, const int& x2) {
        if(abs(x1) != abs(x2)) {
            return abs(x1) > abs(x2);
        }
        return x1 > x2;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, cmp> pq;

    //입력
    cin >> n;

    //연산&출력
    while(n--) {
        cin >> x;

        if(x == 0) {
            if(pq.empty()) {
                cout << "0\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}