#include <iostream>
using namespace std;

int white_cnt = 0;
int blue_cnt = 0;
char paper[129][129];

void divide(int, int, int);

int main() {
	int N; // 한 변의 길이
	cin >> N;

	//색 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	//분할정복으로 구역 나눠서 색종이 개수 구하기
	divide(N, 0, 0);
	cout << white_cnt << "\n" << blue_cnt;
    
    return 0;
}


void divide(int size, int y_start, int x_start) {
	char curr = paper[y_start][x_start];
	for (int i = y_start; i < y_start + size; i++) {
		for (int j = x_start; j < x_start + size; j++) {
			if (curr != paper[i][j]) {
				divide(size / 2, y_start, x_start); //왼쪽 위
				divide(size / 2, y_start, x_start + size / 2);//오른쪽 위
				divide(size / 2, y_start + size / 2, x_start);//왼쪽 아래
				divide(size / 2, y_start + size / 2, x_start + size / 2);//오른쪽 위
				return;
			}
		}
	}
	if (curr == '1') blue_cnt ++;
	else white_cnt ++;

}