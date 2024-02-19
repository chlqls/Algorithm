#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string str) {
    int result = 0;
    for(int i = 0; i< str.length(); i++) {
        if(isdigit(str[i])) {
            result += int(str[i]) - 48;
        }
    }
    return result;
}

bool cmp(const string str1, const string str2) {
    if(str1.length() != str2.length()) {
        return str1.length() < str2.length();
    }
    int sum1 = sum(str1);
    int sum2 = sum(str2);
    if(sum1 != sum2) {
        return sum1 < sum2;
    }return str1 < str2;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<string> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}