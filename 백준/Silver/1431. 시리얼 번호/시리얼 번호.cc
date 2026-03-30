#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool customSort(pair<string, int> a, pair<string, int> b) {
    if (a.first.length() != b.first.length()) {
        return a.first.length() < b.first.length();
    }
    else if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string s;
    cin >> N;

    vector<pair<string, int>> arr(N);

    for(int i = 0; i< N; i++) {
        int  sum = 0;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            if (isdigit(s.at(j))) {
                sum += s.at(j) - '0';
            }
        }
        arr[i].first = s;
        arr[i].second = sum;
    }

    sort(arr.begin(), arr.end(), customSort);

    for (int i = 0; i < N; i++) {
        cout << arr[i].first << '\n';
    }
    
    return 0;
}