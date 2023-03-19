#include <iostream>
using namespace std;

long long int dp[201][201] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	// 예시) 5를 만드는 방법
	// dp[K][N]: K개의 정수로 N 만드는 경우의 수
	// dp[0][5] => 0
	// dp[1][5] = 5 => 1
	// dp[2][5] = 0+5, 1+4, 2+3, 3+2, 4+1, 5+0 => 6
	// dp[3][5] = 0+0+5, 0+1+4, 0+2+3, 0+4+1, 0+5+0, 
	// 1+0+4, 1+1+3, 1+2+2, 1+3+1, 1+4+0,
	// 2+0+3, 2+1+2, 2+2+1, 2+3+0,
	// 3+0+2, 3+1+1, 3+2+0,
	// 4+0+1, 4+1+0,
	// 5+0+0
	// => dp[2][5] + dp[2][4] + dp[2][3] + dp[2][2] + dp[2][1] + dp[2][0]


	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 1000000000;
		}
	
	}

	cout << dp[K][N];
	return 0;
	
}