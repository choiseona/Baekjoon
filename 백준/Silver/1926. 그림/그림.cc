#include <iostream>
#include <queue>
using namespace std;

int n, m; //n:세로, m:가로
bool picture[501][501];
bool visited[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int cnt = 0;
int maxArea = 0;

int BFS(int i, int j) {

	cnt++; // 그림 개수 count

	int area = 0;
	queue <pair<int, int>> q;

	q.push({ i,j });
	visited[i][j] = 1;
	area++; // 그림 넓이 ++
	

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = now_x + dx[i];
			int new_y = now_y + dy[i];

			if (new_x < 0 || new_y <0 || new_x >n || new_y > m || !picture[new_x][new_y] || visited[new_x][new_y]) continue;
			q.push({ new_x,new_y });
			visited[new_x][new_y] = 1;
			area++; //그림 넓이 ++
		}
	}
	return area;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	// 그림 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> picture[i][j];
		}
	}

	// 그림의 개수와 가장 넓은 그림의 넓이 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j] && !visited[i][j]) {
				int area = BFS(i, j);
				if (maxArea < area) {
					maxArea = area;
				}
			}
		}
	}

	cout << cnt << "\n" << maxArea;
}