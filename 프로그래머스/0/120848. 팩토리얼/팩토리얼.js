function solution(n) {
    let answer = 1;
    let multi = 1;
    
    for(let i=1; ;i++){
        multi *= i;
        if(multi > n){
            answer = i-1;
            break;
        }
  
    }
    return answer;
}