#include <iostream>
using namespace std;

int arr[201];

int main() {
	int N, v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num+100]++;
	}
	cin >> v;
	cout<< arr[v+100];

	return 0;
}