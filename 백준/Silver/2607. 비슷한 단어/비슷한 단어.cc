// 2607: 비슷한 단어 (실버3/구현, 문자열)
#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26; //알파벳 종류 개수인 26은 해당 문제에서 자주 사용되므로 전역 상수로 선언

/*
* 원본 단어와의 차이의 개수를 센다.
*/

/*
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

// 각 알파벳의 개수 세기
void countFreq(string word, vector<int> &freq) {
    for (int i = 0; i < word.length(); i++) { //word의 길이만큼 반복문 실행
        freq[word[i] - 'A']++; // word의 i번째 알파벳의 종류를 확인하면서 freq 배열에 알파벳 개수 저장
    }
}

int countDiff(string word, vector<int> original_freq) {
    vector<int> freq(NUM_CHARS, 0);
    int diff = 0; // 원본 단어와의 차이

    countFreq(word, freq); // 각 알파벳의 개수 세기
    
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {
        diff += abs(original_freq[i] - freq[i]); //원본 단어의 각 알파벳 개수와 주어진 단어(word)의 각 알파벳 개수의 차이만큼 diff에 더하기
    }
    return diff;
}

int main() {
    int N, ans=0; //문제 풀이에 필요한 변수 선언 및 초기화
    string original; 
    // 입력
    cin >> N;
    cin >> original;
    vector<int> original_freq(NUM_CHARS, 0); //NUM_CHARS크기의 original_freq 배열을 선언하고 0으로 초기화

    // 연산
    countFreq(original, original_freq); //기준이 되는 첫 번째 단어를 이루는 알파벳 개수 세기

    for (int i = 1; i < N; i++) { //입력받은 N의 크기만큼 반복문 실행
        string word;
        cin >> word;

        int diff = countDiff(word, original_freq); //원본 단어와 주어진 단어와의 차이의 개수 구하기
        // 비슷한 단어 세기
        //1. diff == 0 -> 단어가 같은 구성일 경우 
        //2. diff == 1 -> 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 되는 경우 
        //3. diff == 2 && original.length() == word.length() -> 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            ans++;
        }
    }
    // 출력
    cout << ans;
    return 0;
}