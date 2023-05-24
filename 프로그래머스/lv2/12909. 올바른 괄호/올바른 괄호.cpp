#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0;
    int close = 0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            open ++;
        else
            close++;
        
        if(close > open){
            answer=false;
            break;
        }
        
        if((i == s.size()-1) && (open != close))
            answer=false;
           
    }

    return answer;
}