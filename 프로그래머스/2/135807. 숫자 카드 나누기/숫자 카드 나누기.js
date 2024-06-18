function solution(arrayA, arrayB) {
    const arrayAGCD = arrayA.reduce((cul,cur) => getGCD(cul,cur));
    const arrayBGCD = arrayB.reduce((cul,cur) => getGCD(cul,cur));
    const arrayADivisor = getDivisor(arrayAGCD);
    const arrayBDivisor = getDivisor(arrayBGCD);
    const maxArrayADivisor = getMaxDivisor(arrayADivisor, arrayB);
    const maxArrayBDivisor = getMaxDivisor(arrayBDivisor, arrayA)
    return Math.max(maxArrayADivisor, maxArrayBDivisor)
}

function getMaxDivisor(arrayDivisor, array) {
    let answer;
    for (const divisor of arrayDivisor) { 
        if (array.every(num => num % divisor !== 0)) {
            answer = divisor;
            break; 
        }
    }
    return answer || 0;
}


function getDivisor(number) {
    const answer = [];
    for(let i=1; i<=Math.sqrt(number); i++) {
        if(number % i !==0) continue;
        answer.push(i);
        if(i !== number / i) {
            answer.push(number / i);
        }
    }
    return answer.sort((a,b) => b-a);
}

function getGCD(number1, number2) {
    if(number2 === 0) return number1;
    if(number1 < number2) [number2, number1] = [number1,number2]
    return getGCD(number2, number1 % number2);
}