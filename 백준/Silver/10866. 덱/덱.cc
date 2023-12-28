#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, X;
	cin >> N;

	deque <int> dq;

	while (N--) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		string oper;
		cin >> oper;

		if (oper == "push_front") {
			cin >> X;
			dq.push_front(X);
		}
		else if (oper == "push_back" ) {
			cin >> X;
			dq.push_back(X);
		}
		else if (oper == "pop_front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (oper == "pop_back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}

		}
		else if (oper == "size") {
			cout << dq.size() << "\n";
		}
		else if (oper == "empty") {
			cout << dq.empty() ? 1 : 0;
			cout << "\n";
		}
		else if (oper == "front") {
			if (dq.empty()) cout << -1;
			else cout << dq.front();
			cout << "\n";
		}
		else if (oper == "back") {
			if (dq.empty()) cout << -1;
			else cout << dq.back();
			cout << "\n";
		}
	}
	return 0;
}