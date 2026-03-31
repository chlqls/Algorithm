#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> S;

    // 사전 순으로 가장 뒤에 오게 만드는 방법 = 왼쪽 자리에 최대한 큰 숫자 배치하기
    for (int i = 0; i < N; i++) {
        int max = arr[i], idx = i;
        int range = min(N - 1, i + S);

        // i부터 range까지가 S번의 교환으로 가져올 수 있는 범위
        // 이 사정거리 안에서 가장 큰 숫자 찾기
        for (int j = i; j <= range; j++) {
            if (arr[j] > max) {
                max = arr[j];
                idx = j;
            }
        }

        // 위에서 찾은 최댓값을 i 위치까지 끌고 오기
        for (int j = idx; j > i; j--) {
            swap(arr[j], arr[j - 1]);
            S--;
        }

        if (!S) {
            break;
        }
    }

    for (int v : arr) {
        cout << v << ' ';
    }

    return 0;
}