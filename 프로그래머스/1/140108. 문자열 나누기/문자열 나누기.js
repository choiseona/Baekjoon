function solution(s) {
    let firstCount=0, notFirstCount=0;
    let target, answer = 0;
    
    for(let i=0; i<s.length; i++) {
        if(firstCount === 0) target = s[i];
        
        if(s[i] === target) firstCount++;
        else if(s[i] !== target) notFirstCount++;
        
        if(firstCount !== notFirstCount && i !== s.length-1) continue;
        
        answer++;
        firstCount = notFirstCount = 0;
    }
   return answer;
}