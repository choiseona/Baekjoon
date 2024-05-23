function solution(s, n) {
    const upperACode = 'A'.charCodeAt();
    const lowerACode = 'a'.charCodeAt();
    
    let answer = '';
    
    for(let i=0; i<s.length; i++) {
        if(s[i] === " ") answer += " ";
        
        // 대문자
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            answer +=  String.fromCharCode(upperACode + (s[i].charCodeAt() + n - upperACode) % 26);
        }
        
        else if(s[i] >= 'a' && s[i] <= 'z') {
            answer += String.fromCharCode(lowerACode + (s[i].charCodeAt() + n - lowerACode) % 26);

        }
    }
    
    return answer;
}