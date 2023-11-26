#include <iostream>
using namespace std;

int main() {
	int N;
	int sum = 0;
	int Y=0, M=0;

	cin >> N;

	while (N--) {
		int time;
		cin >> time;
		Y = Y + 10 + time / 30 * 10;
		M = M + 15 + time / 60 * 15;
	}

	if (Y > M) cout << "M " << M;
	else if (M > Y) cout << "Y " << Y;
	else cout << "Y " << "M " << Y;

	return 0;
}
