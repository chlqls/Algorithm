#include <iostream>
#include <vector>

using namespace std;


bool checkRange(pair<char, int> p) {
    //행과 열의 범위 확인
    if(p.first >= 'A' && p.first <= 'H' && p.second >= 1 && p.second <= 8) {
        return true;
    }
    return false;
}

pair<char, int> move(string input, pair<char, int> p) {
    if(input == "R") {
        p.first++;
    } else if(input == "L") {
        p.first--;
    } else if(input == "B") {
        p.second--;
    } else if(input == "T") {
        p.second++;
    } else if(input == "RT") {
        p.first++;
        p.second++;
    } else if(input == "LT") {
        p.first--;
        p.second++;
    } else if(input == "RB") {
        p.first++;
        p.second--;
    } else if(input == "LB") {
        p.first--;
        p.second--;
    }
    return p;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<char, int> king, stone;
    string input;
    int n;

    //입력
    cin >> input;
    king.first = input[0];
    king.second = input[1] - '0';
    cin >> input;
    stone.first = input[0];
    stone.second = input[1] - '0';
    cin >> n;
    
    pair<char, int> new_king, new_stone;

    //연산
    while(n--) {
        cin >> input;
        new_king = move(input, king);
        if(new_king == stone) {
            new_stone = move(input, stone);
        } else {
            new_stone = stone;
        }
        //킹과 돌이 체스판 밖으로 나가지 않았는지 확인
        if(checkRange(new_king) && checkRange(new_stone)) {
            king = new_king;
            stone = new_stone;
        }
    }
    
    //출력
    cout << king.first << king.second << '\n';
    cout << stone.first << stone.second;    

    return 0;
    
}