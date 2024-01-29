#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//DP 문제

int main() {
	int N;
	cin >> N;

	vector <int> dp(1000001);
	dp[2] = 1; //2->1
	dp[3] = 1; //3->1
	//dp[4] = 2; //4->2->1 => 1+dp[i/2]


	//N이 2와 3으로 모두 나누어 떨어지지 않으면 1(1 빼기) + dp[i-1](숫자 i-1의 최소 연산 횟수)
	//N이 2와 3으로 모두 나누어 떨어지면 1(N/2 또는 N/3) + (dp[i/2] 또는 dp[i/3])
	//N이 2로만 나누어 떨어지면 1+dp[i-1] 또는 1+dp[i/2]
	//N이 3으로만 나누어 떨어지면 1+dp[i-1] 또는 1+dp[i/3]
	for (int i = 4; i <= N; i++) {
		if (i % 2 != 0 && i % 3 != 0) {
			dp[i] = 1 + dp[i - 1];
		}
		else if (i % 2 == 0 && i % 3 == 0) {
			dp[i] = min(1 + dp[i / 2], 1 + dp[i / 3]);
		}
		else if (i % 2 == 0 && i % 3 != 0) {
			dp[i] = min(1 + dp[i - 1], 1 + dp[i / 2]);
		}
		else if (i % 2 != 0 && i % 3 == 0) {
			dp[i] = min(1 + dp[i - 1], 1 + dp[i / 3]);
		}
	}

	cout << dp[N];
	return 0;
}
