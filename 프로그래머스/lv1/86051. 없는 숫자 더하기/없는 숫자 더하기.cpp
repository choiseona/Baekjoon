#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector <bool> isExist(10,0);
    
    for(int i=0;i<numbers.size();i++){
        isExist[numbers[i]]=1;
    }
    
    for(int i=0;i<isExist.size();i++){
        if(isExist[i]==0) answer+=i;
    }
    
    return answer;
}