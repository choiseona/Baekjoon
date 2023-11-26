#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long A, B;
	long long bigger, smaller;

	cin >> A >> B;
	if (A > B) {
		bigger = A;
		smaller = B;
		cout << A - B - 1 << "\n";
		for (long long i = B+1; i < A; i++) {
			cout << i << " ";
		}
	}
	else if(A<B) {
		bigger = B;
		smaller = A;
		cout << B - A - 1 << "\n";
		for (long long i = A+1; i < B; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << 0;
	}

	return 0;
}