function solution(n, left, right) {
    const answer = [];
    
    for(let i=left+1; i<=right+1; i++) {
        const x = Math.ceil(i/n);
        const y = i - n*(x-1);
        answer.push(Math.max(x,y))
    }
    
    return answer;
}