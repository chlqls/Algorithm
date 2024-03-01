#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sum(vector<int> &arr_a, vector<int> &arr_b) {
    string result;
    bool ten = false;

    for(int i = 0; i < arr_a.size(); i++) {
        int add = arr_a[i] + arr_b[i];
        if(ten) {
            add++;
        }
        ten = add / 10;
        add %= 10;
        result += add + '0';
    }

    //첫째자리 계산
    if(ten) {
        result += 1 + '0';
    }

    return result;
}

int main() {
    string a, b;

    //입력
    cin >> a >> b;

    //더 긴 문자열을 a로 설정
    if(a.size() < b.size()) {
        swap(a, b);
    }
    
    vector<int> arr_a(a.size());
    vector<int> arr_b(a.size());
    string result;

    //입력받은 값을 각각 배열에 거꾸로 저장
    for(int i = 0; i < a.size(); i++) {
        arr_a[i] = a[a.size() - i - 1] - '0';
        if(i >= b.size()) { //두 수의 길이가 다르면 차이나는 만큼 0으로 채우기
            arr_b[i] = 0;
        }
        else {
            arr_b[i] = b[b.size() - i - 1] - '0';
        }
    }

    //연산
    result = sum(arr_a, arr_b);

    //출력
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    
}