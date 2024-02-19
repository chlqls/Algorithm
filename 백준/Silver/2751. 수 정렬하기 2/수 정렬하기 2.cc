#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted;

void merge(vector<int>& arr, int left, int mid, int right) {
    int pl = left, pr = mid + 1, idx = left;
    while (pl <= mid && pr <= right)
    {
        if(arr[pl] < arr[pr]) {
            sorted[idx++] = arr[pl++];
        }
        else {
            sorted[idx++] = arr[pr++];
        }
    }
    while(pl <= mid) {
        sorted[idx++] = arr[pl++];
    }
    while(pr <= right) {
        sorted[idx++] = arr[pr++];
    }
    for(int i = left; i <= right; i++) {
        arr[i] = sorted[i];
    }
    
}

void mergesort(vector<int> &arr, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n);
    sorted.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    mergesort(arr, 0, n - 1);

    //출력
    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}