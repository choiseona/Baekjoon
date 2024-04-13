function solution(order) {
    return [...order.toString()].filter((x) => parseInt(x)!==0 && parseInt(x) % 3 === 0 ).join("").length;
}