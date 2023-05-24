#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    
    for(int i=0;i<s.size();i++){
        if(n < 0) return false;
        
        if(s[i]=='(')
            n++;
        else
            n--;
    }

    return n==0;
}