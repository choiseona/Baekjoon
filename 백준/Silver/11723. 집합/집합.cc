#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> S;

void add(int);
void remove(int);
void check(int);
void toggle(int);
void all();
void empty();

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;

    cin >> M;//연산 수

    for (int i = 0; i < M; i++) {
        string oper;
        cin >> oper;

        if (oper == "add") {
            int x;
            cin >> x;
            add(x);
        }

        else if (oper == "remove") {
            int x;
            cin >> x;
            remove(x);
        }

        else if (oper == "check") {
            int x;
            cin >> x;
            check(x);
        }

        else if (oper == "toggle") {
            int x;
            cin >> x;
            toggle(x);
        }

        else if (oper == "all") {
            all();
        }

        else
            empty();
    }

    return 0;
}

void add(int x) {
    if (find(S.begin(), S.end(), x) == S.end()) {
        S.push_back(x);
    }
}

void remove(int x) {
    if (find(S.begin(), S.end(), x) != S.end()) {
        S.erase(find(S.begin(), S.end(), x));
    }
}

void check(int x) {
    if (find(S.begin(), S.end(), x) == S.end())
        cout << 0<<"\n";
    else
        cout << 1<<"\n";
}

void toggle(int x) {
    if (find(S.begin(), S.end(), x) != S.end())
        S.erase(find(S.begin(), S.end(), x));
    else
        S.push_back(x);
}

void all() {
    S.clear();
    for (int i = 1; i <= 20; i++) {
        S.push_back(i);
    }
}

void empty() {
    S.clear();
}