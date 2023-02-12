#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[200001] = {};
int ans;
void BFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	BFS(N, K);
	cout << ans;

	return 0;
}

void BFS(int start, int target) {
	queue <pair<int, int>> q;
	q.push(make_pair(start, 0));
	visited[start] = 1;

	while (!q.empty()) {
		int now_val = q.front().first;
		int now_sec = q.front().second;
		q.pop();

		if (now_val == target) {
			ans = now_sec;
			break;
		}

		if ((now_val - 1 >= 0) && (visited[now_val - 1] == 0)) {
			q.push(make_pair(now_val - 1, now_sec + 1));
			visited[now_val - 1] = 1;
		}
		if ((now_val + 1 >= 0) && (visited[now_val + 1] == 0)) {
			q.push(make_pair(now_val + 1, now_sec + 1));
			visited[now_val + 1] = 1;
		}
		if ((2 * now_val <= 200000) && visited[2 * now_val] == 0) {
			q.push(make_pair(now_val * 2, now_sec + 1));
			visited[now_val * 2] = 1;
		}
	}

}
