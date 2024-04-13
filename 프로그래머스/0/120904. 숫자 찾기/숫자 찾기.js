function solution(num, k) {
    const strNum = num.toString();
    const strK = k.toString();
    return strNum.indexOf(strK) >= 0 ? strNum.indexOf(strK)+1  : -1
}