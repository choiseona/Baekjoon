#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	deque <int> dq;
	queue <int> arr;
	int result = 0;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	while (M--) {
		int num;
		cin >> num;
		arr.push(num);
	}

	while (!arr.empty()) {

		if (dq.front() == arr.front()) {
			dq.pop_front();
			arr.pop();
		}

		else {
			int count = 0;
			auto iter = dq.begin();
			while (true) {
				iter++;
				count++;
				if (*iter == arr.front())
					break;
			}

			if (count > dq.size() / 2) {
				while (true) {
					if (dq.front() == arr.front()) break;
					dq.push_front(dq.back());
					dq.pop_back();
					result++;
				}

			}
			else {
				while (true) {
					if (dq.front() == arr.front()) break;
					dq.push_back(dq.front());
					dq.pop_front();
					result++;
				}

			}
		}
	}
	cout << result;

	return 0;
}