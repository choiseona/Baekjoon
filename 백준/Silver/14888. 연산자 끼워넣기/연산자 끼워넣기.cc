#include <iostream>
using namespace std;

int N, num[12], have_oper[4]; //0:+, 1:-, 2:*, 3:/
int min_value = 999999999, max_value = -999999999, result;
string oper = "+-*/";
char ans_oper[12];

void minmax(int);
int possible(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//수열 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	//연산자 개수 입력(0:+, 1:-, 2:*, 3:/)
	for (int i = 0; i < 4; i++) {
		cin >> have_oper[i];
	}

	//최대,최소값 구하기(백트래킹)
	minmax(0);
	//최대,최소값 출력
	cout << max_value << "\n" << min_value;

	return 0;
}

void minmax(int index) {
	if (index == N - 1) { //탈출조건
		int result = num[0];
		for (int i = 0; i < N-1; i++) {
			if (ans_oper[i] == '+') {
				result = result + num[i + 1];
			}
			else if (ans_oper[i] == '-') {
				result = result - num[i + 1];
			}
			else if (ans_oper[i] == '*') {
				result = result * num[i + 1];
			} 
			else if (ans_oper[i] == '/') {
				result = result / num[i + 1];
			}
		}
		if (min_value >= result)
			min_value = result;
		if (max_value <= result)
			max_value = result;

		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			ans_oper[index] = oper[i];

			if (possible(i)) { //유망함수(가지치기)
				have_oper[i]--; //상태 변화
				minmax(index + 1); //재귀 호출
				have_oper[i]++; //상태 복구
			}
		}
	}
}

int possible(int i) {
	if (have_oper[i] <= 0)
		return 0;
	else
		return 1;
}