#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    
    string s = to_string(x);
    for(int i=0;i<s.size();i++){
        sum += s[i]-'0';
    }
    x % sum ? answer = false : answer = true; 
    
    
    return answer;
}