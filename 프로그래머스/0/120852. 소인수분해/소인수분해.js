function solution(n) {
    const answer= new Set();
    let number = n;
    
    for(let i=2; i<=n; i++) {
        while(number % i === 0){
            number /= i;
            answer.add(i)
        }
    }
    return [...answer];
}