#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int count = 0;

	cin >> N;
	while (N--) {
		stack <char> st;
		string S;
		cin >> S;

		for (char s : S) {
			if (st.empty()) {
				st.push(s);
			}

			else if (!st.empty() && st.top() != s) {
				st.push(s);
			}
			else if (!st.empty() && st.top() == s) {
				st.pop();
			}
		}

		if (st.empty()) {
			count++;
		}
	}

	cout << count;
	return 0;
	
}