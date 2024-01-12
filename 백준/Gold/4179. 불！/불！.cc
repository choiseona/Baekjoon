#include <iostream>
#include <queue>
using namespace std;

int R, C;
char miro[1001][1001];

bool fireVisited[1001][1001];
int fireDist[1001][1001];
bool jihunVisited[1001][1001];
int jihunDist[1001][1001];

queue <pair<int, int>> fireQ;
queue<pair<int, int>> jihunQ;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void fireBfs() {
	while (!fireQ.empty()) {
		int fireX = fireQ.front().first;
		int fireY = fireQ.front().second;

		fireQ.pop();

		for (int i = 0; i < 4; i++) {
			int newFireX = fireX + dx[i];
			int newFireY = fireY + dy[i];

			if (newFireX < 0 || newFireY < 0 || newFireX > R - 1 || newFireY > C - 1 || miro[newFireX][newFireY] == '#' || fireVisited[newFireX][newFireY]) continue;
			fireQ.push({ newFireX, newFireY });
			fireVisited[newFireX][newFireY] = 1;
			fireDist[newFireX][newFireY] = fireDist[fireX][fireY] + 1;
		}
	}
}

void jihunBfs() {
	while (!jihunQ.empty()) {
		int jihunX = jihunQ.front().first;
		int jihunY = jihunQ.front().second;

		jihunQ.pop();

		for (int i = 0; i < 4; i++) {
			int newjihunX = jihunX + dx[i];
			int newjihunY = jihunY + dy[i];

			if (newjihunX < 0 || newjihunY < 0 || newjihunX > R - 1 || newjihunY > C - 1 || miro[newjihunX][newjihunY] == '#' || jihunVisited[newjihunX][newjihunY]) continue;
			jihunQ.push({ newjihunX, newjihunY });
			jihunVisited[newjihunX][newjihunY] = 1;
			jihunDist[newjihunX][newjihunY] = jihunDist[jihunX][jihunY] + 1;
		}
	}
}

int solveResult() {
	int result = 999999999;

	for (int i = 0; i < R; i++) {
		if (miro[i][0] == '.' || miro[i][0] == 'J') {
			if (jihunVisited[i][0] && (jihunDist[i][0] < fireDist[i][0] || !fireVisited[i][0]) && (result > jihunDist[i][0])) {
				result = jihunDist[i][0];
			}
		}
		if (miro[i][C - 1] == '.' || miro[i][C - 1] == 'J') {
			if (jihunVisited[i][C - 1] && (jihunDist[i][C - 1] < fireDist[i][C - 1] || !fireVisited[i][C - 1]) && (result > jihunDist[i][C - 1])) {
				result = jihunDist[i][C - 1];
			}
		}
	}

	for (int i = 0; i < C; i++) {
		if (miro[0][i] == '.' || miro[0][i] == 'J') {
			if (jihunVisited[0][i] && (jihunDist[0][i] < fireDist[0][i] || !fireVisited[0][i]) && (result > jihunDist[0][i])) {
				result = jihunDist[0][i];
			}
		}
		if (miro[R - 1][i] == '.' || miro[R - 1][i] == 'J') {
			if (jihunVisited[R - 1][i] && (jihunDist[R - 1][i] < fireDist[R - 1][i] || !fireVisited[R - 1][i]) && (result > jihunDist[R - 1][i])) {
				result = jihunDist[R - 1][i];
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;

	// 미로 입력
	for (int i = 0; i < R; i++) {
		string S;
		cin >> S;

		for (int j = 0; j < C; j++) {
			miro[i][j] = S[j];
		}
	}

	// 불 확산 시간
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (miro[i][j] == 'F') {
				fireQ.push({ i,j });
				fireVisited[i][j] = 1;
			}
		}
	}
	fireBfs();

	// 지훈이 미로 탈출까지 걸리는 시간
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (miro[i][j] == 'J') {
				jihunQ.push({ i,j });
				jihunVisited[i][j] = 1;
			}
		}
	}
	jihunBfs();

	// 미로 가장자리의 불, 지훈 시간 비교하여 지훈 탈출 가능한지 구하기
	int result = solveResult();
	if (result == 999999999) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << result + 1;
	}

}