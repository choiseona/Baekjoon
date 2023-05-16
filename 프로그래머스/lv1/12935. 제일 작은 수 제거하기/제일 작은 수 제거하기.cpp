#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    answer = arr;
    int min = answer[0];
    int idx = 0;
    
    for(int i=1;i<answer.size();i++){
        if(answer[i]<min){
            min = answer[i];
            idx = i;
        }
    }
    answer.erase(answer.begin()+idx);
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}