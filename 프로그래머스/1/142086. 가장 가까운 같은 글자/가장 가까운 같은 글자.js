function solution(s) {
    const answer = [];
    const alphabet = new Map();
    
    [...s].forEach((word, index) => {
        // 앞에 같은 글자가 없을 때
        if (!alphabet.has(word)) answer.push(-1);
        
        // 앞에 같은 글자가 있을 때
        else answer.push(index - alphabet.get(word));
        
        alphabet.set(word, index);
    })
    
    return answer;
              
}