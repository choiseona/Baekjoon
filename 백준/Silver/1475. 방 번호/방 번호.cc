#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N, maximum=-1, index;
	int count[10] = { 0 };
	cin >> N;

	string number = to_string(N);
	for (auto s : number) {
		count[s - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (i != 6 && i != 9 && maximum < count[i]) {
			maximum = count[i];
			index = i;
		}
	}

	if (count[index] >= ceil((count[6] + count[9]) / 2.0))
		cout << count[index];
	else
		cout << ceil((count[6] + count[9]) / 2.0);

	return 0;
}