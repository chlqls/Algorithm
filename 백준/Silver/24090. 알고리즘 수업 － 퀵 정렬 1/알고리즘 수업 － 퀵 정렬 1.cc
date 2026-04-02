#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &A, int p, int r, int K, int &cnt, pair<int, int> &pr) {
    int x = A[r];    // 기준원소
    int i = p - 1;   // i는 x보다 작거나 작은 원소들의 끝지점
    for (int j = p;  j < r; j++) {
        // j는 아직 정해지지 않은 원소들의 시작 지점
        if (A[j] <= x) {
            cnt++;
            if (cnt == K) {
                pr = {A[i + 1], A[j]};
            }
            swap(A[++i], A[j]); // i값 증가 후 A[i] <-> A[j] 교환

        }
    }
        if (i + 1 != r) {
            cnt++;
            if (cnt == K) {
                pr = {A[i + 1], A[r]};
            }
            swap(A[i + 1], A[r]); // i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
        }
    return i + 1;
}

void quick_sort(vector<int> &A, int p, int r, int K, int &cnt, pair<int, int> &pr) { // A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = partition(A, p, r, K, cnt, pr);  // 분할
        quick_sort(A, p, q - 1, K, cnt, pr);  // 왼쪽 부분 배열 정렬
        quick_sort(A, q + 1, r, K, cnt, pr);  // 오른쪽 부분 배열 정렬
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin >> N >> K;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    pair<int, int> pr;

    quick_sort(A, 0, N - 1, K, cnt, pr);

    if (cnt < K) {
        cout << -1 << '\n';
    } else {
        cout << min(pr.first, pr.second) << ' ' << max(pr.first, pr.second) << '\n';
    }

    return 0;
}