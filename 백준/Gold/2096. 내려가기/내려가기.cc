#include <iostream>
#include <algorithm>
using namespace std;

int N;
int input[3];
int max_dp[3] = { 0,0,0 };
int max_temp[3] = { 0,0,0 };
int min_dp[3] = { 0,0,0 };
int min_temp[3] = { 0,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input[j];
			if (i == 0) { //dp초기값 설정
				max_dp[j] = input[j];
				min_dp[j] = input[j];
			}
		}
		if (i != 0) {
			for (int k = 0; k < 3; k++) {
				max_temp[k] = max_dp[k]; //max_dp 저장할 임시 변수
				min_temp[k] = min_dp[k]; //min_dp 저장할 임시 변수
			}
			//가장 큰 값으로 dp 갱신하기
			max_dp[0] = max(max_temp[0] + input[0], max_temp[1] + input[0]);
			max_dp[1] = max({ max_temp[0] + input[1], max_temp[1] + input[1], max_temp[2] + input[1] });
			max_dp[2] = max(max_temp[1] + input[2], max_temp[2] + input[2]);
			//가장 작은 값으로 dp 갱신하기
			min_dp[0] = min(min_temp[0] + input[0], min_temp[1] + input[0]);
			min_dp[1] = min({ min_temp[0] + input[1], min_temp[1] + input[1], min_temp[2] + input[1] });
			min_dp[2] = min(min_temp[1] + input[2], min_temp[2] + input[2]);
		}
	}
	//얻을 수 있는 최대 점수와 최소 점수 출력
	cout << max({ max_dp[0],max_dp[1],max_dp[2] }) << " "
		<< min({ min_dp[0],min_dp[1],min_dp[2] });

	return 0;
}