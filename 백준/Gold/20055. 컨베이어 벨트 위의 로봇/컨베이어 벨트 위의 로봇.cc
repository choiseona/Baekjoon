#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int A[202]; //내구도
	int temp[202] = {};
	bool robot[101] = {}; //로봇 유무
	int ans = 0;

	cin >> N >> K;

	// 내구도 입력
	for (int i = 0; i < 2 * N; i++) {
		cin >> A[i];
	}

	while (true) {
		ans++;

		//#1.벨트가 로봇과 함께 한 칸 회전
		//로봇 이동 시키기
		for (int i = N - 2; i >= 0; i--) {
			if (robot[i] == 1) {
				robot[i] = 0;
				robot[i + 1] = 1;
			}
			//로봇 내리기
			if (robot[N - 1] == 1)
				robot[N - 1] = 0;
		}
		//내구도 이동 시키기
		for (int i = 0; i < 2 * N; i++) {
			temp[i] = A[i];
		}
		A[0] = temp[2 * N - 1];
		for (int i = 1; i < 2 * N; i++) {
			A[i] = temp[i - 1];
		}

		//#2. 가장 먼저 벨트에 올라간 로봇부터,
		//로봇이 한 칸 이동할 수 있다면 이동한다.
		for (int i = N - 2; i >= 0; i--) {
			if (robot[i] == 1) {
				if ((A[i + 1] > 0) && (robot[i + 1] == 0)) {
					robot[i] = 0;
					robot[i + 1] = 1;
					A[i + 1]--;
				}
			}
			//로봇 내리기
			if (robot[N - 1] == 1)
				robot[N - 1] = 0;
		}

		//#3. 내구도가 0이 아니면 로봇 올리기
		if (A[0] > 0 && robot[0] == 0) {
			robot[0] = 1;
			A[0]--;
		}

		int cnt = 0;
		//#4. 내구도가 0인 칸의 개수가 K개 이상이면 종료
		for (int i = 0; i < 2 * N; i++) {
			if (A[i] == 0)
				cnt++;
		}
		if (cnt >= K)
			break;

	}
	cout << ans; //몇 단계일 때 종료됐는지 출력
	return 0;
}