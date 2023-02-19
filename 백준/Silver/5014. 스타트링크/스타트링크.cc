#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001] = {}; //방문 기록 저장
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int F, S, G, U, D;
	
	//F:층 개수, S:지금, G:목표, U:위 몇, D:아래 몇
	cin >> F >> S >> G >> U >> D;
	int ans = -1;

	queue<pair<int,int>> q; //현재 위치랑, cnt 같이 저장
	q.push(make_pair(S, 0));
	visited[S] = 1;

	while (!q.empty()) {
		int now = q.front().first;
		int now_cnt = q.front().second;
		q.pop();

		if (now == G) { //G에 도착했으면 멈추기
			ans = now_cnt;
			break;
		}
		//위로 갈 수 있으면 queue에 넣기
		if (now + U >= 1 && now + U <= F && visited[now + U] == 0) {
			q.push(make_pair(now + U, now_cnt + 1));
			visited[now + U] = 1;
		}
		//아래로 갈 수 있으면 queue에 넣기
		if (now - D >= 1 && now - D <= F && visited[now - D] == 0) {
			q.push(make_pair(now - D, now_cnt + 1));
			visited[now - D] = 1;
		}
	}

	//결과 출력
	if (ans == -1)
		cout << "use the stairs";
	else
		cout << ans;
	return 0;

}