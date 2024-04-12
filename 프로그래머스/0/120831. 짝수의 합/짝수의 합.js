function solution(n) {
    let answer = 0;
    for(let i=n ;i>=0; i--){
        i % 2 === 0 ? answer += i : 0  
    }
    return answer;
}