function solution(arrayA, arrayB) {
    const arrayADivisor = getDivisor(arrayA);
    const arrayBDivisor = getDivisor(arrayB);
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

function getDivisor(array) {
    array = array.sort((a,b) => a-b);
    const answer = [];
    for(let i=1; i<=array[0]; i++) {
        if(array[0] % i !== 0) continue;
        if(array.every(num => num % i ===0)) {
            answer.push(i);
        }
    }
    return answer.sort((a,b) => b-a);
}
