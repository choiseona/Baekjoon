function solution(n) {
    const F = Array.from(Array(n+1), () => 0);
    const divisor = 1234567;
    
    F[0] = 0;
    F[1] = 1;
    
    for(let i=2; i<=n; i++) {
        F[i] = (F[i-2] + F[i-1]) % divisor;
    }
    
    return F[n];
}