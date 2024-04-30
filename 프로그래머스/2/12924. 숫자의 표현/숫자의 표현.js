function solution(n) {
    let oddCount = 0;
    for(let i=1; i<=n; i++) {
        
        if(i % 2 != 0 && n % i === 0)oddCount++;
        
    }
    return oddCount;
}