#include <iostream>
using namespace std;

int main() {
    int N, M;
    int swi[101];
    cin >> N; //스위치 개수

    for (int i = 1; i <= N; i++) { //스위치 상태 저장
        cin >> swi[i];
    }

    cin >> M; //학생 수
    for (int i = 0; i < M; i++) { //학생 정보 입력
        int gender, number;
        cin >> gender >> number;

        if (gender == 1) {//남학생이면
            for (int j = number; j <= N; j += number) { //number의 배수에 대해 
                if (swi[j] == 1) //스위치 상태 바꾸기
                    swi[j] = 0;
                else
                    swi[j] = 1;
            }
        }

        if (gender == 2) { //여학생이면
            //가장 많은 스위치를 포함하는 구간 찾기
            int many = ((number - 1) > (N - number)) ? N-number : N - number-1;

            //좌우 대칭 확인하기
            int cnt = 0;
            for (int j = 1; j<=many; j++) {
                if (swi[number - j] != swi[number + j])
                    break;
                else
                    cnt++; //몇개의 대칭이 같은지 카운트
            }

            //좌우 대칭 구역에 속한 스위치 상태 변경
            for (int j = number - cnt; j <= number + cnt; j++) {
                if (swi[j] == 1)
                    swi[j] = 0;
                else
                    swi[j] = 1;
            }
        }

    }

    

    for (int i = 1; i <= N; i++) {
        cout << swi[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }

    return 0;
}