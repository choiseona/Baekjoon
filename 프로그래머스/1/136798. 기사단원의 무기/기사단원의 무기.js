function solution(number, limit, power) {
    let divisorCounts = [];
    for(let i=1; i<=number; i++) {
        divisorCounts.push(getDivisorCount(i));
    }
    divisorCounts = getLimitedDivisorCount(divisorCounts, limit, power);
    return getTotalSum(divisorCounts);
}

function getTotalSum(array) {
    return array.reduce((cul,cur) => cul + cur, 0);
}

function getLimitedDivisorCount(numbers, limit, power) {
    return numbers.map((num) => num <= limit ? num : power);
}

function getDivisorCount(number) {
    let count = 0;
    for(let i=1; i<= Math.sqrt(number); i++) {
        if(i === Math.sqrt(number)) count++;
        else if(number % i ===0) count+=2;
    }
    return count;
}