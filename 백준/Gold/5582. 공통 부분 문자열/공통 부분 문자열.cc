#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];
string s1, s2;
int max_ = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/*
		A B R A C A D A B R A
	E	0 0 0 0 0 0 0 0 0 0 0
	C	0 0 0 0 1 0 0 0 0 0 0 
	A	1 0 0 1 0 2 0 1 0 0 1
	D	0 0 0 0 0 0 3 0 0 0 0
	A	1 0 0 1 0 1 0 4 0 0 1
	D	0 0 0 0 0 0 2 0 0 0 0
	A	1 0 0 1 0 1 0 3 0 0 1
	B	0 2 0 0 0 0 0 0 4 0 0
	R	0 0 3 0 0 0 0 0 0 5 0
	B	0 1 0 0 0 0 0 0 1 0 0
	C	0 0 0 0 1 0 0 0 0 0 0
	R	0 0 1 0 0 0 0 0 0 1 0
	D	0 0 0 0 0 0 1 0 0 0 0
	A	1 0 0 1 0 1 0 2 0 0 1
	R	0 0 1 0 0 0 0 0 0 1 0
	A	1 0 0 2 0 1 0 1 0 0 2
	*/


	//문자열 두 개 입력
	cin >> s1 >> s2;

	//해당 index에서의 '문자열 공통 부분' 개수는 왼쪽 대각선 위 index의 문자열 공통 부분 개수 +1 한 값이다.
	for (int i = 0; i < s2.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if (s2[i] == s1[j]) {
				if (i != 0 && j != 0) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					
				}
				else {
					dp[i][j] = 1;
					
				}
				if (dp[i][j] > max_)
					max_ = dp[i][j]; //공통 문자열 길이 최대 구하기
			}
		}
	}

	//공통 문자열 길이 최대 출력
	cout << max_;
	return 0;

}