function solution(n) {
    const answer= [];
    let number = n;
    
    for(let i=2; i<=n; i++) {
        let flag = 0;
        while(number % i === 0){
            number /= i;
            flag = 1;
        }
        if(flag === 1) {
            answer.push(i);
        }
    }
    return answer;
}