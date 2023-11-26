#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N, K, result = 0;
	vector<vector<int>> v(2, vector<int>(7,0));

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int gender, grade;
		cin >> gender >> grade;

		v[gender][grade]++;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			result += ceil(v[i][j] / (double)K);
		}
	}

	cout << result;

	return 0;
}