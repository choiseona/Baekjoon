#include <iostream>
using namespace std;

int dice[3];
int maximum = 0;

int main() {

	for (int i = 0; i < 3; i++) {
		cin >> dice[i];
		if (dice[i] > maximum) {
			maximum = dice[i];
		}
	}

	if (dice[0] == dice[1] && dice[1] == dice[2]) {
		cout << 10000 + dice[0] * 1000;
	}
	else if (dice[0] == dice[1] || dice[0] == dice[2]) {
		cout << 1000 + dice[0] * 100;
	}
	else if (dice[1] == dice[2]) {
		cout << 1000 + dice[1] * 100;
	}
	else cout << maximum * 100;

	return 0;
}