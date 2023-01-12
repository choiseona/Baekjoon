#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int stair[301];
	int dp[301]; //각 층에서의 최대값 의미
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	//dp[4] = max(stair[1] + stair[2] + stair[4], stair[1] + stair[3] + stair[4])
	//dp[5] = max(stair[1] + stair[2] + stair[4] + stair[5], stair[1] + stair[3] + stair[5], stair[2] + stair[3] + stair[5])

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}
		
	cout << dp[N];
}