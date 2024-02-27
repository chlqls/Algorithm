#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;

    //입력
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<" ;

    while(!q.empty()) {
        //k번째 사람이 큐의 맨 앞에 오도록 k번째가 아닌 사람은 맨 뒤로 보내기
        for(int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if(q.empty()) {
            cout << ">";
        }
        else {
            cout << ", ";
        }
    }
}