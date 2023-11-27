#include<iostream>
#include<stack>
using namespace std;

int main() {

	int T;
	cin >> T;

	stack<char> stack1;
	stack<char> stack2;

	for (int i = 0; i < T; i++) {

		string password;
		cin >> password;

		for (int j = 0; j < password.size(); j++) {
			if (password[j] == '<') {
				if (stack1.empty()) {
					continue;
				}
				else {
					stack2.push(stack1.top());
					stack1.pop();
				}
			}

			else if (password[j] == '>') {
				if (stack2.empty()) {
					continue;
				}
				else {
					stack1.push(stack2.top());
					stack2.pop();
				}
			}

			else if (password[j] == '-') {
				if (stack1.empty()) {
					continue;
				}
				else {
					stack1.pop();
				}
			}

			else {
				
				stack1.push(password[j]);
			}
			
		}

		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}

		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}

		while (!stack2.empty()) {
			cout << stack2.top();
			stack2.pop();
		}
		cout << "\n";

	}

	return 0;
}
