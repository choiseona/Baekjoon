#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    bool sum[3001]={0};
    
    for(int i=1;i<=sqrt(n);i++){
        if(n % i ==0){
            sum[i]=1;
            sum[n/i]=1;
        }
    }
    
    int answer=0;
    for(int i=1;i<=n;i++){
        if(sum[i]==1){
            answer+=i;
        }
    }
    
    return answer;
}