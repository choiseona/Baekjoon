#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	queue <int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop(); //제일 위 버림

		int front = q.front(); 
		q.pop(); //그 다음 위 빼냄
		q.push(front); //제일 아래로 옮김
	}

	cout << q.front();

	return 0;
}