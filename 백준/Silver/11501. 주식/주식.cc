#include <iostream>
using namespace std;

int stock[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;

	cin >> T; //테스트케이스 수
	for (int i = 0; i < T; i++) {
		cin >> N; //날의 수
		for (int j = 0; j < N; j++) {
			cin >> stock[j]; //날 별 주가 입력
		}

		int max_ = -1; //최대값 -1로 초기화
		long long ans = 0; //최대 이익 0으로 초기화(자료형 주의)
		for (int j = N - 1; j >= 0; j--) { //끝에서부터 탐색

			if (max_ < stock[j]) //지금까지의 최대값 업데이트
				max_ = stock[j];

			else { //지금까지의 최대값이 아니면 (최대값 - 해당 날짜의 주식 가격) 더하기
				ans = ans + (max_ - stock[j]);
			}
		}
		cout << ans << "\n"; //최대 이익 출력
	}
	return 0;
}