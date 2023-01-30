#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int status[21][21];
int sumA, sumB;
int minval = 1000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}
	
	//N이 5면 -> (10000,11000,11100,11110) 1이 1개~4개인 비트마스크 필요함
	for (int i = 1; i < N; i++) {
		sumA = 0; sumB = 0;//초기화
		vector<int> mask; //초기화

		for (int j = 0; j < i; j++) {
			mask.push_back(1);
		}
		for (int j = 0; j < N - i; j++) {
			mask.push_back(0);
		}
		do
		{
			sumA = 0; sumB = 0;//초기화
			vector<int> A; //초기화
			vector<int> B; //초기화

			//팀 나누기
			for (int i = 0; i < N; i++) {
				if (mask[i] == 1)
					A.push_back(i);
				else
					B.push_back(i);
			}

			//각 팀의 능력치 구하기
			for (int i = 0; i < A.size()-1; i++) {
				for (int j = i + 1; j < A.size(); j++) {
					sumA = sumA + status[A[i]][A[j]] + status[A[j]][A[i]];
				}
			}
			for (int i = 0; i < B.size() - 1; i++) {
				for (int j = i + 1; j < B.size(); j++) {
					sumB = sumB + status[B[i]][B[j]] + status[B[j]][B[i]];
				}
			}

			//두 팀의 능력치 차이의 최소값 구하기
			if (minval > abs(sumA - sumB))
				minval = abs(sumA - sumB);
			

		} while (prev_permutation(mask.begin(), mask.end()));

	}

	cout << minval;
	return 0;
}
