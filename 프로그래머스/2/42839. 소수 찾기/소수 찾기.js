const getPermutation = function(arr, selectCount) {
    if(selectCount === 1) return [...new Set(arr)].map((el) => [el]);
    
    const result = [];
    arr.forEach((fixed, index, originArray) => {
        const rest = [...originArray.slice(0, index), ...originArray.slice(index+1)];
        const permutation = getPermutation(rest,selectCount-1);
        const attatched = permutation.map((el) => [fixed, ...el]);
        result.push(...attatched);
    })
    const resultSet = [...new Set(result.map((el) => el.join("")))]
    return resultSet;
}

const isPrime = function (number) {
    if(number === 1) return false;
    for(let i=2; i<=Math.sqrt(number); i++) {
        if(number % i === 0) return false;
    }
    return true;
}

function solution(numbers) {
    let permutation=[];
    let answer = 0;
    
    for(let i=1; i<=numbers.length; i++) {
        permutation = [...permutation, ...getPermutation([...numbers], i)]
    }
    
    for(let i=0; i<permutation.length; i++) {
        if(permutation[i][0] === '0') continue;
        if(isPrime(parseInt(permutation[i]))) answer++;
    }
    
    return answer;
}

