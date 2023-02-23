#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h> //abs
using namespace std;

int N, M;
int A[51][51];
vector <pair<int, int>> cloud;
int d, s;
queue <pair<int, int>> cloud_move;
int dir_r[9] = { 0 , 0, -1, -1, -1, 0, 1, 1, 1 };
int dir_c[9] = { 0 , -1, -1, 0, 1, 1, 1, 0, -1 };
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//각 칸의 물의 양 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	//초기 구름 위치 저장
	cloud.push_back(make_pair(N, 1));
	cloud.push_back(make_pair(N, 2));
	cloud.push_back(make_pair(N - 1, 1));
	cloud.push_back(make_pair(N - 1, 2));

	//구름 이동 정보 저장
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		cloud_move.push(make_pair(d, s));
	}

	while (!cloud_move.empty()) {
		bool isCloud[51][51] = {}; //구름 여부 초기화
		d = cloud_move.front().first; //구름 이동 방향
		s = cloud_move.front().second; //구름 이동 칸 수
		cloud_move.pop();

		//구름 이동
		for (int i = 0; i < cloud.size(); i++) {
			//구름 r 이동
			if ((cloud[i].first + s * dir_r[d]) > 0) {
				if ((cloud[i].first + s * dir_r[d]) % N == 0)
					cloud[i].first = N;
				else
					cloud[i].first = (cloud[i].first + (s * dir_r[d])) % N;
			}
			else
				cloud[i].first = N - (abs((cloud[i].first + (s * dir_r[d]))) % N);

			//구름 c 이동
			if (cloud[i].second + s * dir_c[d] > 0) {
				if ((cloud[i].second + s * dir_c[d]) % N == 0)
					cloud[i].second = N;
				else
					cloud[i].second = (cloud[i].second + (s * dir_c[d])) % N;
			}
			else
				cloud[i].second = N - (abs((cloud[i].second + (s * dir_c[d]))) % N);
		}

		//구름 있는 칸 물의 양 1 증가
		for (int i = 0; i < cloud.size(); i++) {
			A[cloud[i].first][cloud[i].second]++;
			isCloud[cloud[i].first][cloud[i].second] = 1;
		}

		//물복사버그 마법 
		for (int i = 0; i < cloud.size(); i++) {
			for (int j = 2; j < 9; j = j + 2) {
				if (cloud[i].first + dir_r[j] <= N && cloud[i].second + dir_c[j] <= N
					&& cloud[i].first + dir_r[j] > 0 && cloud[i].second + dir_c[j] > 0
					&& A[cloud[i].first + dir_r[j]][cloud[i].second + dir_c[j]] > 0)
					A[cloud[i].first][cloud[i].second]++;
			}
		}

		//구름 사라짐
		cloud.clear();

		//구름 없었던 자리에 구름 생성
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (isCloud[i][j] == 1 || A[i][j] < 2) {
					isCloud[i][j] = 0;
					continue;
				}
				else {
					isCloud[i][j] = 1;
					cloud.push_back(make_pair(i, j));
					A[i][j] -= 2;
				}
			}
		}
	}

	//바구니에 들어있는 물의 양의 합 구해서 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += A[i][j];
		}
	}
	cout << ans;

	return 0;
}
