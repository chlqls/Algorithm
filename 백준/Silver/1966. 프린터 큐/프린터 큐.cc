#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq; // 중요도를 내림차순으로 자동 정렬

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({ priority, i });
            pq.push(priority);
        }

        int count = 0;
        while (!q.empty()) {
            int currentP = q.front().first;
            int currentIndex = q.front().second;
            q.pop();

            // 현재 문서가 가장 높은 중요도인지 확인
            if (pq.top() == currentP) {
                count++;
                pq.pop(); // 인쇄 완료
                if (currentIndex == M) {
                    cout << count << "\n";
                    break;
                }
            }
            else {
                // 중요도가 낮으면 맨 뒤로 다시 보냄
                q.push({ currentP, currentIndex });
            }
        }
    }
    return 0;
}