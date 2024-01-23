#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001][2];
int dist[1001][1001][2];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue <pair<pair<int,int>,int>> q;

int bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;

		q.pop();

		if (x == N - 1 && y == M - 1) {
			return dist[x][y][block];
		}

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			if (new_x < 0 || new_y <0 || new_x > N - 1 || new_y > M - 1 || (map[new_x][new_y] == 1 && block == 1) || visited[new_x][new_y][block]) continue;

			// 벽 && 벽 깰 수 있을 때
			if (block == 0 && map[new_x][new_y] == 1) {
				q.push({ {new_x,new_y},1 });
				visited[new_x][new_y][1] = 1;
				dist[new_x][new_y][1] = dist[x][y][0] + 1;
			}

			// 벽 아닐 때
			else {
				q.push({ {new_x,new_y},block });
				visited[new_x][new_y][block] = 1;
				dist[new_x][new_y][block] = dist[x][y][block] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	// map 입력
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			map[i][j] = S[j] - '0';
		}
	}

	// 최단거리 구하기
	q.push({ {0,0},0 });
	visited[0][0][0] = 1;
	dist[0][0][0] = 1;

	cout << bfs();
}