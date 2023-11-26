#include <iostream>
using namespace std;

int main() {
	string a, b;
	int count[26] = { 0 };
	int result = 0;

	cin >> a >> b;
	for (auto s : a) 
		count[s - 'a']++;
	for (auto s : b)
		count[s - 'a']--;

	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) result += abs(count[i]);
	}
	
	cout << result;

	return 0;
}