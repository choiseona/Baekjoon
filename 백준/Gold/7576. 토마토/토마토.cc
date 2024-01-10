#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomato[1001][1001];
bool visited[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int dist[1001][1001];
int result = 0;
queue <pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_y < 0 || new_x > N - 1 || new_y > M - 1 || tomato[new_x][new_y] != 0 || visited[new_x][new_y]) continue;
			q.push({ new_x, new_y });
			tomato[new_x][new_y] = 1;
			visited[new_x][new_y] = 1;
			dist[new_x][new_y] = dist[x][y] + 1;
			if (dist[new_x][new_y] > result) {
				result = dist[new_x][new_y];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	// 토마토 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
		}
	}

	// 토마토 익히기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1 && !visited[i][j]) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	bfs();

	// 토마토 모두 익는 날짜 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				result = -1;
				break;
			}
		}
	}

	cout << result;
}