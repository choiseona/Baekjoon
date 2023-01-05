#include <iostream>
#include <queue>
using namespace std;

int N, M;
string miro[101];
bool visited[101][101] = {};
int r_dir[4] = { 1,0,0,-1 };
int c_dir[4] = { 0,1,-1,0 };
int dist[101][101] = {}; //최소 이동 거리 저장 배열

void BFS(int, int);

int main() {
	cin >> N >> M;

	//미로 그리기
	for (int i = 0; i < N; i++) {
		cin >> miro[i];
	}

	//길 찾기
	//최소 이동 거리 구하기
	BFS(0, 0);

	//최소 이동 거리 출력
	cout << dist[N - 1][M - 1];
}

void BFS(int r, int c) {
	queue <pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = 1;
	dist[r][c] += 1; 

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int r_new = r + r_dir[i];
			int c_new = c + c_dir[i];

			if ((r_new >= 0) && (r_new < N) && (c_new >= 0) && (c_new < M) &&
				(miro[r_new][c_new] == '1') && (visited[r_new][c_new] == 0)) {
				q.push(make_pair(r_new, c_new));
				visited[r_new][c_new] = 1;
				dist[r_new][c_new] = dist[r][c] + 1; //key point
			}

		}
	}

}