#include<iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	long long sum = 0; //빌딩의 개수가 최대 80000 -> 79999 + 79998 + ... + 1 일 경우 long long
	cin >> N;

	stack <int> buildings;

	for (int i = 1; i <= N; i++) {
		int  height;

		cin >> height;

		while (!buildings.empty()) {
			int left_height = buildings.top();

			if (left_height <= height) {
				buildings.pop();
			}

			else {
				//buildings.size(): 해당 건물을 볼 수 있는 건물의 개수
				sum += buildings.size();
				break;
			}
		}

		buildings.push(height );
	}
	cout << sum;
}