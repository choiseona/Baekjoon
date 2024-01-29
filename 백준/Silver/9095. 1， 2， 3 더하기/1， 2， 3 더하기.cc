#include <iostream>
using namespace std;


int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		int dp[12] = { 0 };

		cin >> n;

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[n] << "\n";

		/*
		dp[1] = 1 => 1
		dp[2] = 1 + 1, 2 => 2
		dp[3] = 1 + 1 + 1, 2 + 1, 1 + 2, 3 => 4
		dp[4] = 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 1 + 3, 3 + 1, 2 + 2 => 7
		*/
	}
}