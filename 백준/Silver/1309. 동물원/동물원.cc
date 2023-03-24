#include <iostream>
using namespace std;

int dp[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	//01 -> 0
	//10 -> 1
	//00 -> 2

	dp[1][0] = 1; //1행이 01인 경우의 수 
	dp[1][1] = 1; //1행이 10인 경우의 수
	dp[1][2] = 1; //1행이 00인 경우의 수

	//현재 행이 01인 경우 -> 전 행이 10 또는 00
	//현재 행이 10인 경우 -> 전 행이 01 또는 00
	//현재 행이 00인 경우 -> 전 행이 01 또는 10 또는 00
	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
	}

	//마지막행(사자를 배치하는 경우의 수)를 9901로 나눈 나머지 출력
	
	/*
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
	이렇게 하면 답이 38278자리수로 unsigned long long을 훨씬 뛰어넘으므로 
	dp를 구할 때마다 %9901을 해서 오버플로우를 방지해야함
	*/
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
	
	return 0;
}