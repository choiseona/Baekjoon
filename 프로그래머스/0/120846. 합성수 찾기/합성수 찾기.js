function solution(n) {
    let answer=0;
    
    const is합성수 = (number) => {
        for(let i=2; i<number; i++){
            if(number % i === 0) return true;
        }
        return false;
    }
    
    for(let i=3; i<=n; i++){
        answer+=is합성수(i)
    }
    
    return answer;
}