#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(1,x); //n개의 원소를 x로 초기화
    for(int i=1;i<n;i++){
        answer.push_back(answer[i-1]+x);
    }
    return answer;
}