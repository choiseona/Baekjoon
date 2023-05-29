#include <iostream>
using namespace std;

int main() {
	string S;
	int time[10];
	int times = 0;

	cin >> S;

	for (int i = 1; i < 10; i++) {
		time[i] = i + 1;
	}

	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= 'A' && S[i] <= 'C') times += time[2];
		else if (S[i] >= 'D' && S[i] <= 'F') times += time[3];
		else if (S[i] >= 'G' && S[i] <= 'I') times += time[4];
		else if (S[i] >= 'J' && S[i] <= 'L') times += time[5];
		else if (S[i] >= 'M' && S[i] <= 'O') times += time[6];
		else if (S[i] >= 'P' && S[i] <= 'S') times += time[7];
		else if (S[i] >= 'T' && S[i] <= 'V') times += time[8];
		else if (S[i] >= 'W' && S[i] <= 'Z') times += time[9];
	}

	cout << times;
}
