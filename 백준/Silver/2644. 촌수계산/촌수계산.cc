#include <iostream>
#include <vector>
using namespace std;

int num, p1, p2, m;
bool par_ch[101][101] = {};
bool visited[101] = {};
int cnt = 0;
int ans;

void DFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num >> p1 >> p2 >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
 		cin >> parent >> child;

		par_ch[parent][child] = 1;
		par_ch[child][parent] = 1;
	}

	DFS(p1, p2);
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}

void DFS(int now, int target) {

	if (now == target) { //탈출 조건
		ans = cnt; 
		return;
	}
	for (int i = 1; i <= num; i++) { 

		if (par_ch[now][i] == 0 || visited[i] == 1) { //가지치기
			continue;
		}
		visited[i] = 1; //상태 변화
		cnt++;

		DFS(i, target); //재귀 호출
		visited[i] = 0; //상태 복구
		cnt--;

	}
}