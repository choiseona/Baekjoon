#include<iostream>
#include<stack>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack <pair<int,int>> numbers; 
	vector <int> result(N, -1); //NGE 저장
	
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;

		//입력한 숫자가 결과가 되는 경우 찾기
		while (!numbers.empty() && numbers.top().second < number) {
			result[numbers.top().first] = number;
			numbers.pop();
		}
		numbers.push({i,number});
	}

	for (int number : result)
		cout << number << " ";

}
