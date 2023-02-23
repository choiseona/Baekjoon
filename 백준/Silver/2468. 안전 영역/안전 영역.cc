#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N;
bool sink[101][101] = {};
int height[101][101];
bool visited[101][101] = {};
void BFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max = 0;
	int cnt = 0;
	int ans = 0;

	//높이 정보 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			//최대 높이 저장
			if (max < height[i][j])
				max = height[i][j];
		}
	}

	for (int i = 0; i <= max; i++) {

		//0으로 초기화
		fill(&sink[0][0], &sink[100][101], 0);
		fill(&visited[0][0], &visited[100][101], 0);


		//물에 잠기는 지점 표시
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (height[j][k] <= i)
					sink[j][k] = 1;
			}
		}

		cnt = 0; //안전 영역 카운트 초기화
		//안전 영역 개수 최대값 구하기
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (sink[j][k] == 1 || visited[j][k] == 1)
					continue;
				else {
					BFS(j, k);
					cnt++;
				}
			}
			if (ans < cnt)
				ans = cnt;
		}
	}
	cout << ans; //안전 영역 최대 개수 출력
	return 0;
}

void BFS(int r, int c) {

	int dir_r[4] = { -1,1,0,0 };
	int dir_c[4] = { 0,0,-1,1 };

	queue <pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = 1;

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_row = row + dir_r[i];
			int new_col = col + dir_c[i];

			if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= N
				|| visited[new_row][new_col] == 1 || sink[new_row][new_col] == 1)
				continue;
			else {
				q.push(make_pair(new_row, new_col));
				visited[new_row][new_col] = 1;
			}
		}
	}
}