#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s[0] >= 'a' && s[0] <='z') s[0] = toupper(s[0]);
    for(int i=1;i<s.size();i++){
        if(s[i-1]!=' '){
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
        }
        else 
            if(s[i] >= 'a' && s[i] <='z') s[i] = toupper(s[i]);
    }
    
    answer = s;
    return answer;
}