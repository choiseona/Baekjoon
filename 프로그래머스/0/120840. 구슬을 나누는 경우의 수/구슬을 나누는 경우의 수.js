function solution(balls, share) {
    const factorial = (number) => {
        let answer=1;
        for(let i=1; i<=number; i++){
            answer*=i;
        }
        return answer
    }
    return Math.round(factorial(balls) / (factorial(balls-share) * factorial(share)))
}