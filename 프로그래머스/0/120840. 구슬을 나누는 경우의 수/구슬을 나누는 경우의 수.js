function solution(balls, share) {
    const factorial = (num) => num === 0 ? 1 : num * factorial(num - 1)
    return Math.round(factorial(balls) / (factorial(balls-share) * factorial(share)))
}