function solution(s) {
    const answer = [];
    const alphabet = {};
    
    [...s].forEach((word, index) => {
        // 앞에 같은 글자가 없을 때
        if (alphabet[word] === undefined) answer.push(-1);
        // 앞에 같은 글자가 있을 때
        else answer.push(index - alphabet[word]);
        
        alphabet[word] = index;
    })
    
    return answer;            
    
}