function solution(s){
    let count = 0;
    let answer = true;
    
    for(let i=0; i<s.length; i++) {
         if (s[i] === ')' && !(count > 0))  {
            answer = false;
         }
         
         else {
             (s[i] === '(') && count++;
             (s[i] === ')') && count--;
         }     
     }
    
    answer =  count === 0 && answer===true ?  true : false;
    return answer;
}