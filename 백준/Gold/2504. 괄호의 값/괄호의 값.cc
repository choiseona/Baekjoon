#include <iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	stack <char> st;
	int result = 0;

	int temp = 1;

	cin >> S;

	// 분배 법칙 이용, '(' : *2, '[': *3
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			temp *= 2;
			st.push(S[i]);
		}
		else if (S[i] == ')') {
			if (st.empty() || st.top() != '(') {
				result = 0;
				break;
			}
			else if (S[i-1] == '(') {
				result += temp;
				temp /= 2;
				st.pop();
			}
			else if (S[i-1] != '(') {
				temp /= 2;
				st.pop();
			}
		}
		else if (S[i] == '[') {
			temp *= 3;
			st.push(S[i]);
		}
		else if (S[i] == ']') {
			if (st.empty() || st.top() != '[') {
				result = 0;
				break;
			}
			else if (S[i - 1] == '[') {
				result += temp;
				temp /= 3;
				st.pop();
			}
			else if (S[i - 1] != '[') {
				temp /= 3;
				st.pop();
			}
		}
	}
	if (!st.empty()) {
		result = 0;
	}
	
	cout << result;
}