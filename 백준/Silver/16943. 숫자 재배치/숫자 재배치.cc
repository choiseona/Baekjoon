#include <iostream>
#include <string>
using namespace std;

int A, B, C;
int max_num = 0, cnt = 0;
int num_cnt[11] = {};
string A_arr, B_arr;
string C_arr = "          ";

void max_(int);
int possible(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	A_arr = to_string(A);

	//각 숫자의 사용가능한 개수 저장
	for (int i = 0; i < A_arr.length(); i++) {
		num_cnt[(A_arr[i] - '0')]++;
	}

	//백트래킹
	max_(0);
	if (cnt == 0) {
		cout << -1;
	}
	else {
		cout << max_num;
	}

	return 0;
}

void max_(int index) {
	if (index == A_arr.length()) { //탈출 조건
		//구한 string을 정수로 변환해서 최대값 구하기
		//cnt == 0 이면 C < B인 것이 하나도 없는 것이므로 -1출력
		C = stoi(C_arr);
		if (C < B) {
			cnt++;
			if (max_num < C)
				max_num = C;
		}
		return;
	}

	else {
		for (int i = 0; i < A_arr.length(); i++) {
			C_arr[index] = A_arr[i];

			if (possible(i)) { //유망함수(가지치기)
				num_cnt[A_arr[i] - '0']--; //상태 변화
				max_(index + 1); //재귀 호출
				num_cnt[A_arr[i] - '0']++; //상태 복구
			}
		}
	}
}

int possible(int i) {
	if (num_cnt[A_arr[i] - '0'] <= 0) {
		return 0;
	}
	if (C_arr[0] == '0') {
		return 0;
	}
	return 1;
}