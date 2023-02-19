#include <iostream>
#include <queue>
using namespace std;

int N, M;
int ice[301][301];
int dir_i[4] = { -1,1,0,0 };
int dir_j[4] = { 0,0,-1,1 };
bool visited[302][302] = {};
int zerocnt[302][302] = {};
int cnt = 0;
int ans = -1;
int iceflag = 0;

void BFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ice[i][j];
		}
	}

	while (true) {
	
		//빙산이 다 녹았으면(모두 0이면) while문 종료
		iceflag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] > 0) {
					iceflag = 1;
					break;
				}
			}
			if (iceflag == 1)
				break;
		}

		if (iceflag == 0)
			break;


		//초기화
		for (int i = 0; i < 302; i++) {
			for (int j = 0; j < 302; j++) {
				visited[i][j] = 0;
				zerocnt[i][j] = 0;
			}
		}

		//너비우선을 몇번하는지 카운트하기
		//1번 넘게 하면 빙산이 분리된 것임
		cnt = 0; //카운트 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ice[i][j] > 0 && visited[i][j] == 0) {
					BFS(i, j);
					cnt++;
				}

			}
		}

		//시간 카운트
		ans++;

		//처음부터 분리돼있으면 0출력해야함
		//처음부터 분리돼있지 않고 빙산 분리됐으면 시간 출력
		if (ans != 0 && cnt > 1) {
			cout << ans;
			return 0;
		}
	}

	//빙산이 다 녹을 때까지 분리되지 않으면 0출력
	cout << 0;
	
	return 0;
}

void BFS(int i, int j) {
	queue <pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = 1;

	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_i = now_i + dir_i[i];
			int new_j = now_j + dir_j[i];

			if (new_i < 0 || new_j < 0 || new_i >= N || new_j >= M)
				continue;

			if (ice[new_i][new_j] > 0 && visited[new_i][new_j] == 0) {
				q.push(make_pair(new_i, new_j));
				visited[new_i][new_j] = 1;
			}
			else if (ice[new_i][new_j] <= 0) {
				zerocnt[now_i][now_j]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ice[i][j] -= zerocnt[i][j];
			if (ice[i][j] < 0)
				ice[i][j] = 0;
		}
	}
}