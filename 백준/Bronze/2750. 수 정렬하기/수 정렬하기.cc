#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int> &arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        for(int j = 0; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    bubblesort(arr);

    //출력
    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}