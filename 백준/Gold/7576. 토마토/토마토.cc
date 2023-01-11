#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomato[1001][1001];
bool visited[1001][1001] = {};
int dist[1001][1001] = {};
int r_dir[4] = { -1,1,0,0 };
int c_dir[4] = { 0,0,-1,1 };
queue <pair<int, int>> q;

void BFS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//토마토 상자 채우기
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j]; //1:익음, 0:안익음, -1:토마토없음

			if (tomato[i][j] == 1) { //맨 처음 익은 토마토 큐에 넣기
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}

	//너비 우선 탐색
	BFS();

}

void BFS() {

	//익은 토마토 상하좌우 토마토 익히기
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int r_new = r + r_dir[i];
			int c_new = c + c_dir[i];

			if ((r_new >= 0) && (c_new >= 0) && (r_new < N) && (c_new < M) &&
				(tomato[r_new][c_new] == 0) && (visited[r_new][c_new] == 0)) {
				tomato[r_new][c_new] = 1;
				q.push(make_pair(r_new, c_new));
				visited[r_new][c_new] = 1;
				dist[r_new][c_new] = dist[r][c] + 1; //key point: 익은 날짜 저장
			}
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//큐가 비었는데 안익은 토마토 있으면 -1 출력
			if (tomato[i][j] == 0) {
				cout << -1;
				return;
			}
			if (max < dist[i][j]) {
				max = dist[i][j];
			}

		}
	}

	cout << max;
	return;
}