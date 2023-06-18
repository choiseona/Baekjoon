#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int car_cnt[101] = {0};
    int A, B, C;
    cin >> A >> B >> C; //주차요금 A,B,C

    for (int i = 0; i < 3; i++) {
        int arrive, leave;
        cin >> arrive >> leave; //도착시간, 떠난시간

        for (int j = arrive; j < leave; j++) { //1분마다 있는 차의 개수 저장 
            car_cnt[j]++;
        }
    }

    int total = 0;
    for (int i = 1; i < 101; i++) {
        if (car_cnt[i] == 1)
            total += A;
        else if (car_cnt[i] == 2)
            total += 2 * B;
        else if(car_cnt[i]==3)
            total += 3 * C;
    }

    cout << total;

    return 0;
}