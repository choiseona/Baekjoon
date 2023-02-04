#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; 
	int cnt = 0;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, home_x, home_y, fes_x, fes_y;
		int beer = 20;
		vector <pair<int, int>> market;
		bool visited[101] = {};
		queue <pair<int, int>> q;
		bool happy_flag = 0;

		cnt++;

		cin >> n; //편의점 개수
		cin >> home_x >> home_y; //집의 좌표
		for (int i = 0; i < n; i++) { //편의점 좌표
			int market_x, market_y;
			cin >> market_x >> market_y;
			market.push_back(make_pair(market_x, market_y));
		}
		cin >> fes_x >> fes_y; //페스티벌 좌표

		//BFS
		q.push(make_pair(home_x, home_y));
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (abs(x - fes_x) + abs(y - fes_y) <= beer * 50) {
				if (cnt == t)
					cout << "happy";
				else
					cout << "happy\n";		
				happy_flag = 1;
				break;
			}

			for (int i = 0; i < n; i++) {
				if (visited[i] == 0) {
					int dif = abs(x - market[i].first) + abs(y - market[i].second);
					if (dif <= beer * 50) {
						q.push(make_pair(market[i].first, market[i].second));
						visited[i] = 1;
					}
				}

			}
		}
		if (happy_flag == 0) {
			if (cnt == t)
				cout << "sad";
			else
				cout << "sad\n";
		}
			
	}
	return 0;
}