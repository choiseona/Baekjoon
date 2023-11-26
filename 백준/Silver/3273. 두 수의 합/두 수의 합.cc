#include <iostream>
using namespace std;

int arr[100001];
bool exist[2000001];

int main() {
	int n, X, result = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> X;

	for (int i = 0; i < n; i++) {
		exist[arr[i]] = true;
		if ((X - arr[i] < 0) || (X-arr[i]==arr[i])) continue;
		if(exist[X - arr[i]]) result++;
	}

	cout << result;
	return 0;
}