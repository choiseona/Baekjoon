#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[26][26];
int visited[26][26] = {};
int dir_r[4] = { 0,0,-1,1 };
int dir_c[4] = { -1,1,0,0 };
int total_cnt = 0;
int res_cnt = 0;
vector <int> v;

void BFS(int,int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//지도 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			map[i][j] = input[j]-'0';
		}
	}

	//그래프 탐색 -> 단지 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((map[i][j] == 1) && (visited[i][j] == 0)) {
				BFS(i, j);
			}
			
		}
	}

	//총 단지수 출력
	cout << total_cnt;
	sort(v.begin(), v.end()); //각 단지내 집의 수 오름차순 정렬
	//각 단지내 집의수 출력
	for (int i = 0; i < v.size(); i++) {
		cout << "\n" << v[i];
	}
	
	return 0;
}

void BFS(int r, int c) {
	total_cnt++;
	queue <pair<int, int>> q;

	q.push(make_pair(r, c));
	visited[r][c] = 1;

	while (!q.empty()) {
		int r_ = q.front().first;
		int c_ = q.front().second;
		q.pop();
		res_cnt++;

		for (int i = 0; i < 4; i++) {
			int new_r = r_ + dir_r[i];
			int new_c = c_ + dir_c[i];

			if ((new_r >= 0) && (new_c >= 0) && (new_r < N) && (new_c < N) && (map[new_r][new_c] == 1) && (visited[new_r][new_c] == 0)) {
				q.push(make_pair(new_r, new_c));
				visited[new_r][new_c] = 1;
			}
		}

	}

	v.push_back(res_cnt);
	res_cnt = 0;
}