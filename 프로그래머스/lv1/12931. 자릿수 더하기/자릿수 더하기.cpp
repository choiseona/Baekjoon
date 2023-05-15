#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string s = to_string(n); //int->string
    
    for(int i=0;i<s.size();i++){
        answer += s[i]-'0'; //char을 int로 변환해서 더하기
    }
    
    return answer;
}