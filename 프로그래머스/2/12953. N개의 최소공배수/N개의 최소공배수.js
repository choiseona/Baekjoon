function solution(arr) {
    const getGCD = (number1, number2) => {
        if(number2 === 0) return number1;
        if(number1 < number2) [number1, number2] = [number2, number1];  
        return getGCD(number2, number1 % number2);
    }
    
    const getLCM = (number1, number2) => {
        return (number1 * number2) / getGCD(number1, number2);
    }
    
    let LCM = getLCM(arr[0],arr[1]);
    for(let i=2; i<arr.length; i++) {
        LCM = getLCM(LCM, arr[i]);
    }
    
    return LCM;
}