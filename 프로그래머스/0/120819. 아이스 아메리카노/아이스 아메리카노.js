function solution(money) {
    const count = Math.floor(money/5500);
    const remain = money % 5500;
    return [count,remain];
}