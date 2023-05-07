#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int numArr[500001];
int frequency[500001];
int uptemp[500001];
int downtemp[500001];
pair<int, int> fre[500001];

bool pair_desc(pair<int,int>, pair<int,int>);
bool desc(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numArr[i];
	}

	//산술평균
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += numArr[i];
	}
	double avg = sum / double(N);
	if (round(avg) == -0) cout << 0;
	else cout << round(avg);
	cout << "\n";

	//중앙값
	for (int i = 0; i < N; i++) {
		uptemp[i] = numArr[i];
	}
	sort(uptemp, uptemp+N);
	int med = uptemp[N / 2];
	cout << med << "\n";

	//최빈값
	bool is_flag = 0;
	int saveidx = 0;
	int fresize = 0;

	fre[0] = make_pair(1, numArr[0]);
	fresize++;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < fresize; j++) {
			if (numArr[i] == fre[j].second) {
				is_flag = 1;
				saveidx = j;
				break;
			}
		}
		
		if (is_flag == 1) {
			fre[saveidx].first++;
		}
		else {
			fre[fresize] = make_pair(1, numArr[i]);
			fresize++;
		}
		is_flag = 0;
	}

	sort(fre, fre + N, pair_desc);
	if (fre[0].first == fre[1].first)
		cout << fre[1].second;
	else
		cout << fre[0].second;
	cout << "\n";

	//범위
	//오름차순 정렬한 uptemp는 위에 구현함
	for (int i = 0; i < N; i++) {
		downtemp[i] = numArr[i];
	}
	sort(downtemp, downtemp + N, desc);
	cout << downtemp[0] - uptemp[0];

	return 0;
}

bool desc(int a, int b) {
	return a > b;
}
bool pair_desc(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

