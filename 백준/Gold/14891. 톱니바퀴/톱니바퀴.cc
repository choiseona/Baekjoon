#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//4개의 톱니 입력
	string wheel[5];
	for (int i = 1; i <= 4; i++) {
		cin >> wheel[i];
	}

	//K번 회전
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int rotate[5] = {}; //각 톱니의 회전 방향 저장
		int num, dir; //회전을 시작 톱니 idx, 회전 방향
		cin >> num >> dir;

		rotate[num] = dir;
		int now_dir = dir;

		//왼쪽 톱니바퀴의 회전 방향 결졍하기
		//1:시계, -1:반시계, 0:그대로
		for (int j = num; j > 1; j--) {
			if (wheel[j][6] != wheel[j-1][2]) {
				rotate[j-1] = -now_dir;
				now_dir = -now_dir;
			}
			else {
				rotate[j - 1] = 0;
				break;
			}
		}
		//오른쪽 톱니바퀴의 회전 방향 결정하기
		now_dir = dir;
		for (int j = num; j < 4; j++) {
			if (wheel[j][2] != wheel[j + 1][6]) {
				rotate[j + 1] = -now_dir;
				now_dir = -now_dir;
			}
			else {
				rotate[j + 1] = 0;
				break;
			}
		}
		//톱니바퀴 회전시키기
		for (int i = 1; i <= 4; i++) {
			if (rotate[i] == 0)
				continue;
			if (rotate[i] == 1) { //시계방향
				string temp = wheel[i];
				wheel[i][0] = temp[7];
				for (int j = 1; j < 8; j++) {
					wheel[i][j] = temp[j - 1];
				}
			}
			else if (rotate[i] == -1) { //반시계방향
				string temp = wheel[i];
				wheel[i][7] = temp[0];
				for (int j = 0; j < 7; j++) {
					wheel[i][j] = temp[j + 1];
				}
			}
		}

	}
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (wheel[i][0] == '1') {
			ans += pow(2, i-1);
		}
	}

	cout << ans;
	return 0;
}