#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    //입력
    cin >> N >> M;
    set<string> S;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        S.insert(str);
    }

    //연산
    int result = 0;
    for(int j = 0; j < M; j++) {
        string str;
        cin >> str;
        auto iter = S.find(str); //M개의 문자열이 집합 S에 포함되어있는지 확인
        if(iter != S.end()) {
            result++;
        }
    }

    //출력
    cout << result << '\n';

    return 0;
}