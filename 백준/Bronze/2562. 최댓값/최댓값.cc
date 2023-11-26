#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int maximum = 0;
	int index = -1;

	for (int i = 1; i <= 9; i++) {
		int num;
		cin >> num;

		if (maximum < num) {
			maximum = num;
			index = i;
		}
	}

	cout << maximum << "\n" << index;
	return 0;
}
