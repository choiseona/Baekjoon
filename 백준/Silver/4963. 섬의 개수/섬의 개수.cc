#include <iostream>
#include <queue>
using namespace std;

void BFS(int a, int b);
int w, h;
bool matrix[50][50] = {};
bool visited[50][50] = {};
queue <pair<int, int>> q;
int cnt = 0;

int r_dir[8] = { -1, 1, 0, 0 , -1, -1, 1, 1};
int c_dir[8] = { 0, 0, -1, 1 , -1, 1, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {

		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		//초기화
		cnt = 0;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				matrix[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		//지도 채우기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> matrix[i][j];
			}
		}

		//탐색
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (matrix[i][j] == 1 && visited[i][j] == 0) {
					cnt++;
					BFS(i, j);
				}
			}
		}

		cout << cnt << "\n";

	}
	return 0;
}

void BFS(int a, int b) {
	visited[a][b] = 1;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {
			int r_new = r + r_dir[i];
			int c_new = c + c_dir[i];

			if ((r_new >= 0 && r_new < h) && (c_new >= 0 && c_new < w)
				&& (visited[r_new][c_new] == 0) && (matrix[r_new][c_new] == 1)) {
				visited[r_new][c_new] = 1;
				q.push(make_pair(r_new, c_new));
			}
		}
	}
}