#include <iostream>
#include <string>
using namespace std;

int main() {
	int count[10] = { 0 };
	int A, B, C;
	cin >> A >> B >> C;

	string s = to_string(A * B * C);
	for (auto word : s) {
		count[word - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << count[i] << "\n";
	}
	return 0;
}