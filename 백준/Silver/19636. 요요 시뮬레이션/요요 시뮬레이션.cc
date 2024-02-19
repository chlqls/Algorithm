#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int W0, I0, T, D, I, A; //순서대로 입력받을 변수들
    
    //입력
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;
    
    //연산
    int W1 = W0;//W1는 일일 기초 대사량의 변화를 고려하지 않았을 때의 다이어트 후 예상 체중
    int W2 = W0; //W2는 일일 기초 대사량의 변화를 고려했을 때의 다이어트 후 예상 체중
    int B = I0; //B는 변화하는 일일 기초 대사량
    
    int add = I - (I0 + A); //(일일 에너지 섭취량 − 일일 에너지 소비량)
    
    W1 += add * D;

    for(int i = 0; i < D; i++) {
        W2 += add;
        if(abs(add) > T) {
            B += floor(add / 2.0);
        }
        add = I - (B + A);
    }
    
    //출력
    if(W1 <= 0) {
        cout << "Danger Diet" << '\n';
    }
    else {
        cout << W1 << " " << I0 << '\n';
    }
    if(W2 <= 0 || B <= 0) {
        cout << "Danger Diet" << '\n';
    }
    else {
        cout << W2 << " " << B << " ";
        if(I0 - B > 0) {
            cout << "YOYO";
        }
        else {
            cout << "NO";
        }
    }
    

    return 0;
    
}