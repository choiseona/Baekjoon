#include <iostream>
using namespace std;

int main() {
    int N, score, P;
    cin >> N >> score >> P; //N: 리스트에 있는 점수 개수, score:태수의 새로운 점수, P:랭킹 리스트 올라갈 수 있는 개수
    int list[51];

    for (int i = 0; i < N; i++) { //리스트에 있는 점수 입력
        cin >> list[i];
    }

    int rank = 1;
    int cnt = 0;
    for (int i = 0; i < N; i++) { //등수 구하기
        if (score < list[i])
            rank++;
        else if (score == list[i])
            rank = rank;
        else
            break;
        cnt++; //랭킹 리스트에 올라갈 수 있는지 구하기
    }

    if (cnt >= P) //랭킹 리스트에 못 올라가면
        rank = -1;

    if (N == 0) //아직 랭킹리스트에 아무것도 없으면
        rank = 1;

    cout << rank;
    return 0;


}