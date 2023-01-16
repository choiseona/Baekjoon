#include <iostream>
#include <vector>
using namespace std;

int N;
char sign[10];
string min_value = "9999999999";
string max_value = "0000000000";

char arr[11];
int visited[10] = {};

void minmax(int);
int possible(int, int);

int main() {
	//부호 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sign[i];
	}

	//최대,최소값 구하기
	minmax(0);

	//최대값,최소값 출력
	cout << max_value << "\n";
	cout << min_value;

	return 0;
}

void minmax(int index) {

	if (index == N + 1) { //탈출 조건
		if (min_value > arr) {
			min_value = arr;
		}
		if (max_value < arr) {
			max_value = arr;
		}
		return; 
	}
	else {
		for (int i = 0; i <= 9; i++) {
			arr[index] = i + '0';

			if (possible(index, i)) { //유망함수(가지치기)
				visited[i] = 1; //상태 변화
				minmax(index + 1); //재귀호출
				visited[i] = 0; //상태 복구
			}
		}
	}
}

int possible(int index, int i) {

	if (visited[i] == 0) {
		if (index == 0) {
			if (arr[0] == '0' && sign[0] == '>')
				return 0;
		}
		else {
			if (sign[index - 1] == '>') {
				if (arr[index - 1] > arr[index])
					return 1;
				else
					return 0;
			}
			else if (sign[index - 1] == '<') {
				if (arr[index - 1] < arr[index])
					return 1;
				else
					return 0;
			}
		}
		return 1;
	}
	else
		return 0;

}
