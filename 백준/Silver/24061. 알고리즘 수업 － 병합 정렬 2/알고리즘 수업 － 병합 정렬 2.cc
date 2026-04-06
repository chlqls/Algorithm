#include <iostream>
#include <vector>

using namespace std;

int K, cnt = 0;
vector<int> tmp;

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(vector<int> &A, int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++]; // tmp[t] <- A[i]; t++; i++;
        }
        else {
            tmp[t++] = A[j++]; // tmp[t] <- A[j]; t++; j++;
        }
    }
    while (i <= q) { // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    }
    while (j <= r) { // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    }
    i = p;
    t = 1;
    while (i <= r) { // 결과를 A[p..r]에 저장
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == K) {
            for (int v : A) {
                cout << v << " ";
            }
            exit(0); // 원하는 값 찾으면 출력하고 바로 프로그램 종료
        }
    }
}

void merge_sort(vector<int> &A, int p, int r) { // A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(A, p, q);      // 전반부 정렬
        merge_sort(A, q + 1, r);  // 후반부 정렬
        merge(A, p, q, r);        // 병합
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N >> K;

    // tmp 크기 설정
    tmp.resize(N + 1);

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    merge_sort(A, 0, N - 1);

    cout << -1 << '\n';

    return 0;
}