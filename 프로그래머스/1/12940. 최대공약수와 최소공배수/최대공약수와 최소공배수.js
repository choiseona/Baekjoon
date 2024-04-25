function solution(n, m) {
    const min = Math.min(n,m);
    const max = Math.max(n,m);
    
    const getGCD = (max,min) => min % max === 0 ? max : getGCD(min, max % min);  
    const getLCM = (max,min) => (max * min) / getGCD(max,min);
    
    return [getGCD(max,min), getLCM(max,min)];
}