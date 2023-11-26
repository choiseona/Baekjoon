#include <iostream>
using namespace std;

int arr[21], temp[21];

int main() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
		temp[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;

		for (int j = a; j <= b; j++) {
			arr[j] = temp[a +(b-j)];
		}
		
		for (int j = a; j <= b; j++) {
			temp[j] = arr[j];
		}
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
