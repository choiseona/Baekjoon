#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B;
	int bigger, smaller;

	cin >> A >> B;
	if (A > B) {
		bigger = A;
		smaller = B;
		cout << A - B - 1 << "\n";
		for (int i = B+1; i < A; i++) {
			cout << i << " ";
		}
	}
	else if(A<B) {
		bigger = B;
		smaller = A;
		cout << B - A - 1 << "\n";
		for (int i = A+1; i < B; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << 0;
	}

	return 0;
}