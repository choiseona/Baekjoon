function solution(s) {
    let count = 0;
    let target;
    let answer = 0;
    
    for(let i=0; i<s.length; i++) {
        if(count === 0) target = s[i];
        
        if(s[i] === target) count++;
        else if(s[i] !== target) count--;
        
        if(count !== 0 && i !== s.length-1) continue;
        
        answer++;
        count = 0;
    }
   return answer;
}