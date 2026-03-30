#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Country {
    int code;
    int gold, silver, bronze;
};

// 비교 함수 정의
bool customSort(Country a, Country b) {
    if (a.gold != b.gold) {
        return a.gold > b.gold;
    }
    else if (a.silver != b.silver) {
        return a.silver > b.silver;
    }
    return a.bronze > b.bronze;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, index = 0;
    cin >> N >> K;

    vector<Country> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i].code >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
    }

    // 다중 조건 정렬
    sort(arr.begin(), arr.end(), customSort);

    // K의 위치 찾기
    for (int i = 0; i < N; i++) {
        if (arr[i].code == K) {
            // K와 메달 구성이 완벽하게 똑같은 첫 번째 나라가 몇 번째 인덱스에 있는지를 확인
            for (int j = 0; j <= i; j++) {
                if (arr[j].gold == arr[i].gold && arr[j].silver == arr[i].silver && arr[j].bronze == arr[i].bronze) {
                    cout << j + 1 << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}