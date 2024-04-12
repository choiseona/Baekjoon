function solution(dot) {
    const [num1, num2] = dot;
    if(num1 > 0 && num2 > 0){
        return 1;
    }
    else if(num1 > 0 && num2 < 0) {
        return 4;
    }
    else if(num1 < 0 && num2 < 0) {
        return 3;
    }
    else if(num1 <0 && num2 > 0){
        return 2;
    }
}