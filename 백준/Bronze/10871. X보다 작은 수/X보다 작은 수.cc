#include <iostream>
using namespace std;

int main() {
	int N, X, A;
	cin >> N >> X;

	while (N--) {
		cin >> A;
		if (A < X) cout << A << " ";
	}

	return 0;
}