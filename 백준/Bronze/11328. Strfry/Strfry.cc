#include <iostream>
using namespace std;



int main() {
	int N;
	cin >> N;

	while (N--) {
		int cnt[26] = { 0 };
		bool possible = true;
		string a, b;

		cin >> a >> b;
		for (auto s : a) {
			cnt[s - 'a']++;
		}
		for (auto s : b) {
			cnt[s - 'a']--;
		}

		for (int i = 0; i < 26; i++) {
			if (cnt[i] != 0) {
				possible = false;
				break;
			}
		}

		if (possible) cout << "Possible";
		else cout << "Impossible";
		cout << "\n";
	}
	return 0;
}