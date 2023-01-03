#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
bool link[1001][1001] = {};
bool visited[1001] = {};
void DFS(int);
void BFS(int);
void reset();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	//정점 사이에 간선 그리기
	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		link[num1][num2] = 1;
		link[num2][num1] = 1;
	}

	//깊이 우선 탐색
	reset();
	DFS(V);
	cout << "\n";

	//너비 우선 탐색
	reset();
	BFS(V);

}

void reset() {
	for (int i = 0; i < N+1; i++) {
		visited[i] = 0;
	}
	return;
}

void BFS(int v) {
	queue <int> q;
	q.push(v);
	visited[v] = 1;

	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << ' ';

		for (int i = 1; i <= N; i++) {
			if ((link[v][i] == 1) && (visited[i] == 0)) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	return;
}

void DFS(int v) {
	cout << v << ' ';
	visited[v] = 1;

	for (int i = 1; i <= N; i++) {
		if ((link[v][i] == 1) && (visited[i] == 0)) {
			DFS(i);
		}
	}
	return;
}