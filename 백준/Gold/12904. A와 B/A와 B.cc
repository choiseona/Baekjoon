#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string target;
	string now;
	cin >> target >> now;

	while (true) {
		if (now.size() == target.size())
			break;
		//문자열 맨 뒤에 A가 있으면 문자열의 뒤에 A를 추가한 것이므로
		//원래 문자열 구하려면 맨 뒤 A를 제거해야함
		if (now[now.size() - 1] == 'A')
			now.pop_back();
		//문자열 맨 뒤에 B가 있으면 문자열을 뒤집고 뒤에 B를 추가한 것이므로
		//원래 문자열을 구하려면 맨 뒤 B를 제거한 후 문자열을 뒤집어야함
		else if (now[now.size() - 1] == 'B') {
			now.pop_back();
			reverse(now.begin(), now.end());
		}
	}

	if (target.compare(now) == 0)
		cout << 1;
	else
		cout << 0;

	return 0;

}

