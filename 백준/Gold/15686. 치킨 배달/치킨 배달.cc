#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int city[51][51];
	vector <pair<int, int>> chic; //전체 치킨집 좌표 저장
	vector <pair<int, int>> home; //집 좌표 저장
	vector<int> temp;
	int min_distance = 999999;
	cin >> N >> M;

	//도시 정보 채우기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j]; //0:빈 칸, 1:집, 2:치킨집
			if (city[i][j] == 2) {
				chic.push_back(make_pair(i, j));
			}
			else if (city[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
		}
	}

	/*
	prev_permutation(순열)을 이용해 combination(조합)을 구할 것임
	prev_permutation은 내림차순 정렬된 데이터로만 제대로 사용 가능
	prev_permutation은 다음 순열을 구할 수 있으면 true를 반환하고
	다음 순열을 구할 수 없으면 false를 return함 -> do while 사용하기
	*/
	
	//5개의 치킨집중 2개의 치킨집만 선택할거면 (1,1,0,0,0) 배열이 필요함
	for (int i = 0; i < M; i++) {
		temp.push_back(1);
	}
	for (int i = 0; i < chic.size() - M; i++) {
		temp.push_back(0);
	}


	//해당 인덱스가 순열에서 1을 의미하면 해당 치킨집을 포함하란 의미이므로 선택된 치킨집 배열에 넣어준다.
	do {
		vector <pair<int, int>> sel_chic; //M개 치킨집 좌표 저장
		for (int i = 0; i < chic.size(); i++) {
			if (temp[i] == 1) {
				sel_chic.push_back((make_pair(chic[i].first, chic[i].second)));
			}
		}

		//도시의 치킨 거리의 최솟값 구하기
		int total_distance = 0;
		for (int i = 0; i < home.size(); i++) {
			int hf = home[i].first;
			int hs = home[i].second;
			int min = 999999;

			for (int j = 0; j < sel_chic.size(); j++) {
				int cf = sel_chic[j].first;
				int cs = sel_chic[j].second;
				int cur_distance = abs(hf - cf) + abs(hs - cs);

				if (cur_distance < min) {
					min = cur_distance;
				}
			}
			total_distance = total_distance + min;

		}
		if (total_distance < min_distance) {
			min_distance = total_distance;
		}
	} while (prev_permutation(temp.begin(), temp.end()));
	
	cout << min_distance;
}

