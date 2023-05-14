#include <iostream>
using namespace std;

void dfs(int, int, int);
int R, C, K;
bool visited[6][6] = { 0 };
int x_dir[4] = { 0,0,-1,1 };
int y_dir[4] = { -1,1,0,0 };
int ans = 0;
string road[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;

	//길 입력
	for (int i = 0; i < R; i++) {
		cin >> road[i]; 

	}

	visited[R - 1][0] = 1;
	dfs(R-1, 0,1); //한수는 현재 왼쪽 아래점에 있음
	cout << ans;

	return 0;
}

void dfs(int y, int x, int dis) {
	if (y == 0 && x == C-1 && dis == K) { //집은 오른쪽 위에 있음
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int new_y = y + y_dir[i];
		int new_x = x + x_dir[i];
		if (new_y < 0 || new_x < 0 || new_y >= R || new_x >= C) continue;
		if (visited[new_y][new_x] == 1 || road[new_y][new_x] == 'T') continue;

		visited[new_y][new_x] = 1;
		dfs(new_y, new_x, dis+1);
		visited[new_y][new_x] = 0; //길이 겹치는 부분이 있을 수 있기 때문에 visited 0으로 초기화해주기
	}

}