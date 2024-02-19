#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

bool cmp(const student& s1, const student& s2) {
    if(s1.kor == s2.kor) {
        if(s1.eng == s2.eng) {
            if(s1.math == s2.math) {
                return s1.name < s2.name; //이름이 사전 순 순으로 증가하는 순서
            }
            return s1.math > s2.math; //수학 점수가 감소하는 수서
        }
        return s1.eng < s2.eng; //영어 점수가 증가하는 순서
    }
    return s1.kor > s2.kor; //국어 점수가 감소하는 순서
}

bool cmpAdv(const student& s1, const student& s2) {
    if(s1.kor != s2.kor) {
        return s1.kor > s2.kor;
    }
    if(s1.eng != s2.eng) {
        return s1.eng < s2.eng;
    }
    if(s1.math != s2.math) {
        return s1.math > s2.math;
    }
    return s1.name < s2.name;
}

int main() {
    int n;
    vector<student> my_class;

    //입력
    cin >> n;
    my_class.assign(n, {});
    
    for(int i = 0; i < n; i++) {
        cin >> my_class[i].name >> my_class[i].kor >> my_class[i].eng >> my_class[i].math;
    }

    //연산
    sort(my_class.begin(), my_class.end(), cmp);

    //출력
    for(int i = 0; i < my_class.size(); i++) {
        cout << my_class[i].name << '\n';
    }

    return 0;
}