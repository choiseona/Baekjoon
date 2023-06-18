#include <iostream>
using namespace std;

struct Cnt {
    int gold;
    int silver;
    int bronze;
    int grade;
};

int main() {
    int N, K;
    cin >> N >> K; //N:국가 수 K:등수를 알고 싶은 국가

    Cnt cnt[1001];
    int K_gold, K_silver, K_bronze;

    for (int i = 0; i < N; i++) { //국가의 메달 개수 저장
        int id, gold, silver, bronze;
        cin >> id >> gold >> silver >> bronze;
        cnt[id].gold = gold;
        cnt[id].silver = silver;
        cnt[id].bronze = bronze;

        if (id == K) { //K 국가이면 따로 저장하기
            K_gold = gold;
            K_silver = silver;
            K_bronze = bronze;
        }
    }
    int K_grade = 0;
    for (int i = 1; i <= N; i++) { //K국가의 등수 구하기
        if (i == K) continue;
        else {
            if (cnt[i].gold > K_gold) K_grade++;
            else if ((cnt[i].gold == cnt[K].gold) && (cnt[i].silver > K_silver)) K_grade++;
            else if ((cnt[i].gold == K_gold) && (cnt[i].silver = K_silver) && (cnt[i].bronze > K_bronze)) K_grade++;
        }
    }

    cout << K_grade;
    return 0;
}