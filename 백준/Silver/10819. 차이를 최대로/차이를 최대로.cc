#include <iostream>
#include <algorithm> //next_permutation(순열)
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int num[9];
	int max_sum = -1; //최대값 구하기 위한 변수

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num + N); //next_permutation 해주기 '전에' 무조건 오름차순 정렬된 상태여야함

	do {

		int sum = 0;
		for (int i = 0; i < N-1; i++) {
			sum += abs(num[i] - num[i + 1]);
		}

		if (max_sum < sum)
			max_sum = sum;

	} while (next_permutation(num, num + N)); //오름차순 정렬된 것에 대한 순열 구하기
	
	cout << max_sum;

	return 0;
}