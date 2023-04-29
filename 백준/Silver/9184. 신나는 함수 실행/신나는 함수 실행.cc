#include <iostream>
using namespace std;

//메모제이션을 이용해 시간을 줄여줘야 한다.
//w(20,20,20)이 최대이기 때문에 dp[21][21][21]만 할당
int dp[21][21][21];
int recur(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a, b, c) << "\n";
	}

	return 0;
}

int recur(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return recur(20, 20, 20);

	if (dp[a][b][c])
		return dp[a][b][c];

	else if (a < b && b < c)
		return dp[a][b][c] = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);
	else
		return dp[a][b][c] = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);
}