#include <iostream>
#include <algorithm>
using namespace std;

int N;
int home[1001][3];
int dp[1001][3]; //각 단계에서의 최소값 저장

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> home[i][j];
		}
	}

	dp[1][0] = home[1][0];
	dp[1][1] = home[1][1];
	dp[1][2] = home[1][2];

	/*
	dp[2][0] = min(home[1][1], home[1][2]) + home[2][0];
	dp[2][1] = min(home[1][0], home[1][2]) + home[2][1];
	dp[2][2] = min(home[1][0], home[1][1]) + home[2][2];
	*/

	for (int i = 2; i <= N; i++) {

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + home[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + home[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + home[i][2];

	}

	cout << min({ dp[N][0], dp[N][1], dp[N][2] });

	return 0;
}