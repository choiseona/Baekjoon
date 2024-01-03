#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main() {
	while (true) {
		string S;
		stack <char> st;
		string result = "";

		getline(cin, S);

		if (S == ".") break;

		for (char s : S) {
			if (s == '(' || s == '[') {
				st.push(s);
			}
			else if (s == ')') {
				if (st.empty() || st.top() == '[') {
					result = "no";
					break;
				}
				st.pop();
			}
			else if (s == ']') {
				if (st.empty() || st.top() == '(') {
					result = "no";
					break;
				}
				st.pop();
			}
			else if (s == '.') {
				if (st.empty()) {
					result = "yes";
				}
				else
					result = "no";
			}
		}
		cout << result << "\n";
	}
}
