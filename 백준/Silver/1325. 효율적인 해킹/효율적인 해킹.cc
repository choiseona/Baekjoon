#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int cnt = 0, max_cnt = 0;
vector <int> v[100001];
bool visited[100001] = {};
int res_cnt[100001] = {};
void BFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	//신뢰 관계 그리기 (A B -> B 해킹하면 A 해킹 가능)
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[B].push_back(A);
	}

	//너비 우선 탐색
	for (int i = 1; i <= N; i++) {
		BFS(i);
	}

	//한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 정렬하여 출력
	for (int i = 1; i <= N; i++) {
		if (res_cnt[i] == max_cnt) {
			cout << i << " ";
		}
	}
}

void BFS(int num) {
	cnt = 0;
	for (int i = 0; i < 100001; i++) {
		visited[i] = 0;
	}
	queue <int> q;
	q.push(num);

	while (!q.empty()) {
		int qnum = q.front();
		q.pop();
		visited[qnum] = true;
		cnt++;
		res_cnt[num]++;

		for (int i = 0; i < v[qnum].size(); i++) {
			if (visited[v[qnum][i]] == 0) {
				q.push(v[qnum][i]);
				visited[v[qnum][i]] = true;
			}
		}
	}
	max_cnt = max(cnt, max_cnt);
}
