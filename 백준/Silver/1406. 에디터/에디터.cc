#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char>s1;
	stack<char>s2;
	char ch;
	char ch2;
	int count;
	int count2 = 0; //전체 개수 카운트
	int count3 = 0; //s2 개수 카운트
	vector<char>c;

	while (true) {
		ch = cin.get();
		if (ch == '\n')
			break;
		s1.push(ch);
		count2++;
	}

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> ch;

		if (ch == 'P') {
			cin >> ch2;
			s1.push(ch2);
			count2++;
		}

		else if (ch == 'L') {
			if (s1.empty()) {
				continue;
			}
			else {
				s2.push(s1.top());
				s1.pop();
				count3++;
			}
		}

		else if (ch == 'D') {
			if (count3 == 0) {
				continue;
			}
			else {
				s1.push(s2.top());
				s2.pop();
				count3--;
			}
		}

		else if (ch == 'B') {
			if (s1.empty()) {
				continue;
			}
			else {
				s1.pop();
				count2--;
			}
		}
	}

	for (int i = 0; i < count3; i++) {
		s1.push(s2.top());
		s2.pop();
	}

	for (int i = 0; i < count2; i++) {
		c.push_back(s1.top());
		s1.pop();
	}


	for (int i = count2 - 1; i >= 0; i--) {
		cout << c[i];
	}


	return 0;

}