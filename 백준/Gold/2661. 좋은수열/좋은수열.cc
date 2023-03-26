#include <iostream>
using namespace std;

int N;
int sequence[81];
bool same;

void good_seq(int);
bool possible(int);

int main() {
	cin >> N;
	good_seq(0);

	return 0;
}

void good_seq(int index) {
	if (index == N ) { //탈출조건 
		//정답 수열 출력
		for (int i = 0; i < N; i++) {
			cout << sequence[i];
		}
		exit(0);
	}
	//1,2,3 돌아가면서 가능한지 체크
	for (int i = 1; i <= 3; i++) {
		sequence[index] = i;
		if (possible(index)==1) 
			good_seq(index + 1);		
		else
			continue;
	}
}

//현재 index 기준 맨뒤쪽부터 한자리씩, 두자리씩, 세자리씩, ... 비교
bool possible(int index) {
	for (int i = 1; i <= (index + 1) / 2; i++) {
		same = 1;
		for (int j = index; j > index - i; j--) {
			if (sequence[j] != sequence[j - i]) {
				// sequence[4]  sequence[3] (한자리 비교)
				// sequence[4]  sequence[2] (두자리 비교)
				// sequence[3]  sequence[1] (두자리 비교)
				same = 0;
				break;
			}
		}
		//똑같은 부분 수열이 하나라도 있으면 나쁜 수열
		if (same == 1)
			return 0;
	}
	//똑같은 부분 수열이 없으므로 좋은 수열
	return 1;
		
}