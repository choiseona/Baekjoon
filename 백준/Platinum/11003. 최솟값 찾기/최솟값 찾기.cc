#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;

	vector <int> A(N+1);

	deque<pair<int,int>> dq;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	/*
	
	1 5 2 3 6 2 3 7 3 5 2 6
	2*i+1이 L의 배수이면 맨 앞 삭제
	 
	i=1 -> A(-1) ~ A(1) 1 => 큐에 1 삽입(1) -> 1
	i=2 -> A(0) ~ A(2) 1,5 => 큐에 5 삽입(1,5) -> 1
	i=3 -> A(1) ~ A(3) 1,5,2 => 큐에서 5 삭제, 2 삽입(1,2) -> 1 
	i=4 -> A(2) ~ A(4) 5,2,3 => (맨 앞 삭제) -> 큐에 3 삽입(2,3) -> 2
	i=5 -> A(3) ~ A(5) 2,3,6 => 큐에 6 삽입(2,3,6) -> 2 
	i=6 -> A(4) ~ A(6) 3,6,2 => (맨 앞 삭제) -> 큐에 6,3 삭제 2 삽입 (2) -> 2
	i=7 -> A(5) ~ A(7) 6,2,3 => 큐에 3 삽입(2,3) -> 2 

	*/

	for (int i = 1; i <= N; i++) {
		if (!dq.empty() && (i - (dq.front().first)) % L == 0) dq.pop_front();
		while (!dq.empty() && (dq.back().second > A[i])) dq.pop_back();
		dq.push_back({ i,A[i] });

		cout << dq.front().second << " ";
	}

}