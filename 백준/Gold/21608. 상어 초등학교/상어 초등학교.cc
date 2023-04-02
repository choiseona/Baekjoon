#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>, pair<int, int>);

int main() {
	int N, num;
	vector <int> stu[401];
	int dir_r[4] = { 0,0,-1,1 };
	int dir_c[4] = { -1,1,0,0 };
	int map[401][401] = {};
	int order[401] = {};


	cin >> N; 

	for (int i = 0; i < N * N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			//stu[i][0]: 학생의 번호, 나머지는 좋아하는 학생의 번호
			stu[i].push_back(num); 
		}
		order[stu[i][0]] = i;
	}

	/*
	1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
	3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 
	그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다
	*/

	for (int i = 0; i < N * N; i++) {
		vector <pair<int, int>> candidate1;
		vector <pair<int, int>> candidate2;

		int max_nei_cnt = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				//빈 자리가 아니면 pass
				if (map[r][c] != 0)
					continue;

				//빈 자리면 1번 조건 확인
				int nei_cnt = 0;
				for (int l = 0; l < 4; l++) {
					int new_r = r + dir_r[l];
					int new_c = c + dir_c[l];
					//근처 자리가 빈 자리가 아니면 좋아하는 사람인지 확인
					if (new_r >=0 && new_c >=0 && new_r <N && new_c < N && map[new_r][new_c] != 0) {
						for (int m = 1; m < 5; m++) {
							if (stu[i][m] == map[new_r][new_c])
								nei_cnt++;
						}
					}
				}
				//1번 조건 만족하는 후보칸 벡터에 저장
				if (nei_cnt > max_nei_cnt) {
					candidate1.erase(candidate1.begin(), candidate1.end());
					candidate1.push_back(make_pair(r, c));
					max_nei_cnt = nei_cnt;
				}
				else if (nei_cnt == max_nei_cnt)
					candidate1.push_back(make_pair(r, c));

			}
		}
		//2번 조건 확인 
		int max_empty_cnt = 0;
		for (int j = 0; j < candidate1.size(); j++) {
			int r = candidate1[j].first;
			int c = candidate1[j].second;

			//비어있는 주변 칸이 가장 많은 칸 구하기
			int empty_cnt = 0;
			for (int k = 0; k < 4; k++) {
				int new_r = r + dir_r[k];
				int new_c = c + dir_c[k];
				if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N && map[new_r][new_c] == 0)
					empty_cnt++;
			}
			if (empty_cnt > max_empty_cnt) {
				candidate2.erase(candidate2.begin(), candidate2.end());
				candidate2.push_back(make_pair(r, c));
				max_empty_cnt = empty_cnt;
			}
			else if (empty_cnt == max_empty_cnt)
				candidate2.push_back(make_pair(r, c));
		}

		//3번 조건 확인
		//candidate2 pair 벡터를 first로 1차 정렬, second로 2차 정렬
		sort(candidate2.begin(), candidate2.end(), compare);
		int r = candidate2[0].first;
		int c = candidate2[0].second;
		map[r][c] = stu[i][0];

	}

	//학생의 만족도 구하기
	int ans = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {

			int love_cnt = 0;
			for (int j = 0; j < 4; j++) {
				int new_r = r + dir_r[j];
				int new_c = c + dir_c[j];
				if (new_r >= 0 && new_c >= 0 && new_r < N && new_c < N) {
					for (int i = 1; i < 5; i++) {
						if (map[new_r][new_c] == stu[order[map[r][c]]][i])
							love_cnt++;
					}
					
				}
			}
			if (love_cnt == 0)
				ans += 0;
			else if (love_cnt == 1)
				ans += 1;
			else if (love_cnt == 2)
				ans += 10;
			else if (love_cnt == 3)
				ans += 100;
			else if (love_cnt == 4)
				ans += 1000;
		}
	}


	cout << ans;
	return 0;

}

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}