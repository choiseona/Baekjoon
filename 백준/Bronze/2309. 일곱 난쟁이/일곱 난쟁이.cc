#include <iostream>
#include <algorithm>
using namespace std;

int total[9];
int fake[2];
int sum = 0;

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> total[i];
		sum += total[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - total[i] - total[j] == 100) {
				fake[0] = total[i];
				fake[1] = total[j];
			}
		}
	}
	sort(total, total + 9);

	for (int i = 0; i < 9; i++)
		if (total[i] != fake[0] && total[i] != fake[1]) cout << total[i] << "\n";
	
	return 0;
}