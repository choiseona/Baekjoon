#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	stack<pair<int,int>> st;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;

		while (!st.empty()) {
			int left_index = st.top().first;
			int left_height = st.top().second;

			// 레이저 신호 수신 가능 탑 발견
			if (height < left_height) {
				cout << left_index << " ";
				break;
			}
			
			// (왼쪽이) 수신 불가능한 탑일 때
			st.pop();
		}

		// 수신 가능한 탑이 없을 때
		if (st.empty()) {
			cout << 0 << " ";
		}

		// 방금 입력한 탑 push
		// 왼쪽 탑이 수신 불가능해서 st.pop()했다면 다시 push 해줄 필요 없음
		// why? 방금 입력한 탑이 더 높기 때문에 왼쪽으로 넘어갈 일 없음
		st.push({ i,height });
	}

	return 0;
}