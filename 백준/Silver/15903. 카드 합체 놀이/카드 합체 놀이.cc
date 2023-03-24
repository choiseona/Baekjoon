#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	long long int card_cnt[1001];
	long long int ans = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card_cnt[i];
	}

	for (int i = 0; i < m; i++) {
		long long int sum = 0; //초기화
		sort(card_cnt, card_cnt + n); //오름차순 정렬
		sum = card_cnt[0] + card_cnt[1]; //카드 합치기
		card_cnt[0] = sum; //계산 값 덮어쓰기
		card_cnt[1] = sum; //계산 값 덮어쓰기
	}

	//놀이 점수 구하기
	for (int i = 0; i < n; i++) {
		ans += card_cnt[i];
	}
	//놀이 점수 출력
	cout << ans;

	return 0;

}