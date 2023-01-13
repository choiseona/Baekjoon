#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[100001];
	int dp[100001];
	cin >> N;

	//수열 입력
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//규칙 찾기
	dp[0] = arr[0];
	//dp[1] = max(dp[0] + arr[1], arr[1]);
	//dp[2] = max(arr[0] + arr[1] + arr[2], arr[1] + arr[2], arr[2]);
	//dp[3] = max(arr[0] + arr[1] + arr[2] + arr[3], arr[1] + arr[2] + arr[3], arr[2] + arr[3], arr[3]);
	//dp[i] = max(dp[i - 1] + arr[i], arr[i]);

	//각 단계에서의 최대값을 dp배열에 저장
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	//내림차순 정렬해서 제일 앞의 원소(가장 큰 수) 출력
	sort(dp, dp + N, greater<>());
	cout << dp[0];
}

