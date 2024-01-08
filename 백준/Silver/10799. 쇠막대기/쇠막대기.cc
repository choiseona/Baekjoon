#include <iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	stack <char> st;
	int result = 0;

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			st.push(S[i]);
		}
		else if (S[i] == ')' && S[i - 1] == '(') {
			st.pop();
			result += st.size();
		}
		else if (S[i] == ')' && S[i - 1] == ')') {
			st.pop();
			result++;
		}
	}
	
	cout << result;
}

