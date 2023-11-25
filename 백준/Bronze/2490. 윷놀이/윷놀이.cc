#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int front=0, back = 0;
		for (int j = 0; j < 4; j++) {
			int yoot;

			cin >> yoot;

			if (yoot == 0) back++;
			else front++;
		}

		if (front == 0) cout << "D";
		else if (front == 1) cout << "C";
		else if (front == 2) cout << "B";
		else if (front == 3) cout << "A";
		else cout << "E";
		cout << "\n";
	}
	return 0;
}