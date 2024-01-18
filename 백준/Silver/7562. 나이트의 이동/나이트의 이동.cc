#include <iostream>
#include <queue>
using namespace std;

int l, night_x, night_y, target_x, target_y;
bool visited[301][301];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
int dist[301][301];
queue <pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (x == target_x && y == target_y) return;

		for (int i = 0; i < 8; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x <0 || new_y <0 || new_x > l - 1 || new_y > l - 1 || visited[new_x][new_y]) continue;
			dist[new_x][new_y] = dist[x][y] + 1;
			q.push({ new_x, new_y });
			visited[new_x][new_y] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> l >> night_x >> night_y >> target_x >> target_y;
		q = queue<pair<int, int>>();
		fill(&visited[0][0], &visited[300][300], 0);
		fill(&dist[0][0], &dist[300][300], 0);

		q.push({ night_x, night_y });
		bfs();

		cout << dist[target_x][target_y] << "\n";
	}
}