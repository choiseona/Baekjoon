#include <iostream>
#include <queue>
using namespace std;

int w, h;
char building[1001][1001];
bool fireVisited[1001][1001];
bool sangVisited[1001][1001];
int fireDist[1001][1001];
int sangDist[1001][1001];
queue <pair<int, int >> fireQ;
queue <pair<int, int>> sangQ;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


void fireBfs() {
	while (!fireQ.empty()) {
		int x = fireQ.front().first;
		int y = fireQ.front().second;

		fireQ.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_y < 0 || new_x > h - 1 || new_y > w - 1 || fireVisited[new_x][new_y] || building[new_x][new_y] == '#') continue;
			fireQ.push({ new_x, new_y });
			fireVisited[new_x][new_y] = 1;
			fireDist[new_x][new_y] = fireDist[x][y] + 1;
		}
	}
}

void sangBfs() {
	while (!sangQ.empty()) {
		int x = sangQ.front().first;
		int y = sangQ.front().second;

		sangQ.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_y < 0 || new_x > h - 1 || new_y > w - 1 || sangVisited[new_x][new_y] || building[new_x][new_y] != '.') continue;
			sangQ.push({ new_x, new_y });
			sangVisited[new_x][new_y] = 1;
			sangDist[new_x][new_y] = sangDist[x][y] + 1;
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		fill(&building[0][0], &building[1000][1000], 0);
		fill(&fireVisited[0][0], &fireVisited[1000][1000], 0);
		fill(&sangVisited[0][0], &sangVisited[1000][1000], 0);
		fill(&fireDist[0][0], &fireDist[1000][1000], 0);
		fill(&sangDist[0][0], &sangDist[1000][1000], 0);
		fireQ = queue < pair<int, int>>();
		sangQ = queue<pair<int, int>>();

		cin >> w >> h;


		// 빌딩 입력
		for (int i = 0; i < h; i++) {
			string S;
			cin >> S;

			for (int j = 0; j < w; j++) {
				building[i][j] = S[j];
			}
		}

		// 불 이동
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (building[i][j] == '*') {
					fireQ.push({ i,j });
					fireVisited[i][j] = 1;
				}
			}
		}
		fireBfs();

		// 상근 이동
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (building[i][j] == '@') {
					sangQ.push({ i,j });
					sangVisited[i][j] = 1;
				}
			}
		}
		sangBfs();

		// 탈출 시간 구하기
		int result = 999999999;
		for (int i = 0; i < w; i++) {
			if (building[0][i] == '#' || building[0][i] == '*') continue;
			if (!sangVisited[0][i]) continue;
			if (fireVisited[0][i]) {
				if (fireDist[0][i] > sangDist[0][i] && result > sangDist[0][i]) result = sangDist[0][i];
			}
			if (!fireVisited[0][i]) {
				if (result > sangDist[0][i]) result = sangDist[0][i];
			}
		}

		for (int i = 0; i < w; i++) {
			if (building[h - 1][i] == '#' || building[h-1][i] == '*') continue;
			if (!sangVisited[h-1][i]) continue;
			if (fireVisited[h-1][i]) {
				if (fireDist[h-1][i] > sangDist[h-1][i] && result > sangDist[h-1][i]) result = sangDist[h-1][i];
			}
			if (!fireVisited[h-1][i]) {
				if (result > sangDist[h-1][i]) result = sangDist[h-1][i];
			}
		}

		for (int i = 0; i < h; i++) {
			if (building[i][0] == '#' || building[i][0] == '*') continue;
			if (!sangVisited[i][0]) continue;
			if (fireVisited[i][0]) {
				if (fireDist[i][0] > sangDist[i][0] && result > sangDist[i][0]) result = sangDist[i][0];
			}
			if (!fireVisited[i][0]) {
				if (result > sangDist[i][0]) result = sangDist[i][0];
			}
		}


		for (int i = 0; i < h; i++) {
			if (building[i][w-1] == '#' || building[i][w-1] == '*') continue;
			if (!sangVisited[i][w-1]) continue;
			if (fireVisited[i][w-1]) {
				if (fireDist[i][w-1] > sangDist[i][w-1] && result > sangDist[i][w-1]) result = sangDist[i][w-1];
			}
			if (!fireVisited[i][w-1]) {
				if (result > sangDist[i][w-1]) result = sangDist[i][w-1];
			}
		}

		if (result == 999999999) cout << "IMPOSSIBLE";
		else
			cout << result+1;
		cout << "\n";

	}
}