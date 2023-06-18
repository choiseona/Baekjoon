#include <iostream>
using namespace std;

int main() {
    int P;
    int nums[20];
    cin >> P; //테스트 케이스 수

    for (int i = 0; i < P; i++) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int T;
        cin >> T;
        for (int j = 0; j < 20; j++) { //줄서기 할 아이들의 키 입력
            cin >> nums[j];

        }

        int cnt = 0;
        int key, k;
        for (int j = 1; j < 20; j++) { //삽입정렬
            key = nums[j];
            for (k = j - 1;( k >= 0) && (nums[k] > key); k--) {
                nums[k + 1] = nums[k];
                cnt++; 
            }
            nums[k + 1] = key;

        }
        cout <<T<<" "<< cnt << "\n";

    }

    return 0;

}