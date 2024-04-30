const getZeroCount = (s) => {
    return s.split("0").length-1;
}

const removeNumberZero = (s) => {
   return s.replace(/0/g,"");
}

const makeDecimalToBinary = (number) => {
    return number.toString(2);
}

function solution(s) {
    let newS = JSON.parse(JSON.stringify(s));
    let zeroCount = 0;
    let changeCount = 0;
    
    while(true) {
        if(newS === "1") break;
        zeroCount += getZeroCount(newS);
        changeCount++;
        const nonZeroS = removeNumberZero(newS);
        newS = makeDecimalToBinary(nonZeroS.length);
    }

    return [changeCount, zeroCount];
}

