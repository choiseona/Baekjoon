#include <iostream>
#include<stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		string S;
		stack <char> st;
		string result = "YES";

		cin >> S;
		for (char s : S) {
			if (s == '(') {
				st.push(s);
			}
			else if (!st.empty() && st.top() == '('  && s == ')') {
				st.pop();
			}
			else {
				result = "NO";
			}
		}

		if (!st.empty()) {
			result = "NO";
		}

		cout << result << "\n";
	}
}