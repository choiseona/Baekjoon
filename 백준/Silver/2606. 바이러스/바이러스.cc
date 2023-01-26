#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, n1, n2;
bool visited[101] = {};
int cnt = 0;
vector <int> v[101]; //이차원 벡터
void BFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//컴퓨터 연결하기 입력
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	//1번 컴퓨터와 연결된 컴퓨터 개수 너비우선탐색으로 찾기
	BFS(1);
	return 0;
}

void BFS(int n) {
	queue <int> q;
	q.push(n);
	visited[n] = 1;

	while (!q.empty()) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < v[f].size(); i++) {
			if (visited[v[f][i]] == 0) {
				cnt++;
				q.push(v[f][i]);
				visited[v[f][i]] = 1;
			}
		}
	}
	cout << cnt;
}