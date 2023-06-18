#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

int main() {
    string s; //대소문자로 이루어진 알파벳 단어
    cin >> s;

    map <char, int> alpha;
    for (int i = 0; i < s.size(); i++) {
        alpha[toupper(s[i])]++;
    }

    vector <pair<char, int>> vec(alpha.begin(), alpha.end());
    sort(vec.begin(), vec.end(), cmp);

    if (vec.size() == 1)
        cout << vec[0].first;

    else {
        if (vec[0].second == vec[1].second)
            cout << '?';
        else
            cout << vec[0].first;
    }

    return 0;

}