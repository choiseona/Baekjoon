#include <iostream>
#include <algorithm>
using namespace std;

int nums[5];
int sum = 0;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> nums[i];
		sum += nums[i];
	}
	sort(nums, nums + 5);
	cout << sum / 5 << "\n" << nums[2];
	return 0;
}