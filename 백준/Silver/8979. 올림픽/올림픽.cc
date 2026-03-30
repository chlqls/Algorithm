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
        return a.gold < b.gold;
    }
    else if (a.silver != b.silver) {
        return a.silver < b.silver;
    }
    return a.bronze < b.bronze;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, rank = 1, index;
    cin >> N >> K;

    vector<Country> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i].code;
        cin >> arr[i].gold;
        cin >> arr[i].silver;
        cin >> arr[i].bronze;
    }

    // 다중 조건 정렬
    sort(arr.begin(), arr.end(), customSort);
    
    for (int i = 0; i < N; i++) {
        rank++;
        if (arr[i].code == K) {
            index = i;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (arr[i].gold == arr[index].gold && arr[i].silver == arr[index].silver && arr[i].bronze == arr[index].bronze) {
            rank--;
        }
    }
    cout << rank << '\n';
    
    return 0;
}