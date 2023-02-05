#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	int sensor_idx;
	vector <int> sensor;
	vector <int> dist;
	int ans = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> sensor_idx;
		sensor.push_back(sensor_idx);
	}

	//센서 위치 오름차순 정렬
	sort(sensor.begin(), sensor.end());

	//센서의 인접 거리 구해서 저장(최소값 구하기 위해)
	for (int i = 0; i < N - 1; i++) {
		dist.push_back(sensor[i + 1] - sensor[i]);
	}

	//센서 간 인접 거리 오름차순 정렬
	sort(dist.begin(), dist.end());

	//집중국이 K개 이므로 N-K개의 인접 거리만 더해주면 됨
	for (int i = 0; i < N-K; i++) {
		ans += dist[i];
	}

	cout << ans;
	return 0;
}