#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(int, int);
int M, N, K; //세로, 가로, 직사각형 개수
bool paper[101][101] = {};
bool visited[101][101] = {};
int dir_r[4] = { 0,0,-1,1 };
int dir_c[4] = { -1,1,0,0 };
vector <int> cnts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	//모눈종이에 직사각형 그리기
	//참고로 그림을 x축 대칭 한거랑 결과는 같음
	for (int i = 0; i < K; i++) {
		int left_d_x, left_d_y, right_up_x, right_up_y;
		cin >> left_d_x >> left_d_y >> right_up_x >> right_up_y;
		for (int r = left_d_y; r < right_up_y; r++) {
			for (int c = left_d_x; c < right_up_x; c++) {
				paper[r][c] = 1;
			}
		}
	}

	//직사각형 안 그려져 있는 곳 탐색하기
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] ==0 && paper[i][j] == 0)
				BFS(i, j);
		}
	}

	//영역의 개수 출력
	//각 영역의 넓이 오름차순 정렬
	sort(cnts.begin(), cnts.end());
	cout << cnts.size() << "\n";
	for (int i = 0; i < cnts.size(); i++) {
		cout << cnts[i] << " ";
	}
	
	return 0;
}

void BFS(int r, int c) {
	int cnt = 0;
	queue <pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = 1;

	while (!q.empty()) {
		int r_ = q.front().first;
		int c_ = q.front().second;
		q.pop();
		cnt++;
		
		for (int i = 0; i < 4; i++) {
			int new_r = r_ + dir_r[i];
			int new_c = c_ + dir_c[i];
			if (new_r < 0 || new_c < 0 || new_r >= M || new_c >= N || visited[new_r][new_c] == 1 || paper[new_r][new_c] == 1)
				continue;
			else {
				q.push(make_pair(new_r, new_c));
				visited[new_r][new_c] = 1;
			}
		}
	}
	cnts.push_back(cnt);
}