#include <iostream>
#include <algorithm>
using namespace std;

int n;
int triangle[501][501];
int dp[501][501];
int maxsum = -1;

int main() {
	
	cin >> n;
	//정수 삼각형 채우기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	//dp[0][0] = triangle[0][0]
	
	//dp[1][0] = dp[0][0] + triangle[1][0]
	//dp[1][1] = dp[0][0] + triangle[1][1]
	
	//dp[2][0] = dp[1][0] + triangle[2][0]
	//dp[2][1] = max(dp[1][0], dp[1][1]) + triangle[2][1]
	//dp[2][2] = dp[1][1] + triangle[2][2]

	//dp[3][0] = dp[2][0] + triangle[3][0]
	//dp[3][1] = max(dp[2][0], dp[2][1]) + triangle[3][1]
	//dp[3][2] = max(dp[2][1], dp[2][2]) + triangle[3][2]
	//dp[3][3] = dp[2][2] + triangle[3][3];

	//각 위치에서의 최대값 찾아서 dp에 저장
	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][0] + triangle[i][0];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}

	//dp[n-1][0]...dp[n-1][n-1]중의 최대값 찾기
	for (int i = 0; i < n; i++) {
		if (maxsum < dp[n - 1][i])
			maxsum = dp[n - 1][i];
	}

	cout << maxsum;

	return 0;
}

