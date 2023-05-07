#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> vertex[1001];
bool visited[1001] = { 0 };
int cnt = 0;

void DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //간선으로 연결되지 않아도 연결 요소 1개로 봐야함
		vertex[i].push_back(i);
	}

	for (int i = 0; i < M; i++) { //간선 연결하기
		int u, v;
		cin >> u >> v;
		vertex[u].push_back(v); //방향 없는 그래프
		vertex[v].push_back(u); //방향 없는 그래프
	}

	for (int i = 1; i <= N; i++) { //DFS이용해서 연결요소 개수 구하기
		if (vertex[i].size() != 0 && visited[i] == 0) {
			DFS(i);
			cnt++;
		}
	}


	cout << cnt;
	return 0;
}

void DFS(int a) {
	visited[a] = 1;
	for (int i = 0; i < vertex[a].size(); i++) {
		if (visited[vertex[a][i]] == 0) {
			DFS(vertex[a][i]);
		}
	}
}