#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;
    priority_queue<int> max_heap;

    while(n--) {
        cin >> x;
        if(x == 0) {
            if(max_heap.empty()) {
                cout << -1 << '\n';
            }
            else {
            cout << max_heap.top() << '\n';
            max_heap.pop();
            }
        }
        else {
            int y;
            for(int i = 0; i < x; i++) {
                cin >> y;
                max_heap.push(y);
            }
        }
    }

    return 0;
}