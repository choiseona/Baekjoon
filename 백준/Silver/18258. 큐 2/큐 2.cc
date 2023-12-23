#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	queue <int> q;

	while (N--) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		string oper;
		cin >> oper;

		if (oper == "push") {
			int num;
			cin >> num;
			q.push(num);
		}

		else if (oper == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}

		else if (oper == "size") {
			cout << q.size() << "\n";
		}

		else if (oper == "empty") {
			cout << q.empty() ? 1 : 0;
			cout << "\n";
 		}

		else if (oper == "front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}

		else if (oper == "back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
}