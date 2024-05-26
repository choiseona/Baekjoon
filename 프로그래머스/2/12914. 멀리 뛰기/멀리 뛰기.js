function solution(n) {
    const MOD = 1234567;
    
    // dp 배열 초기화
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = 1;

    // 각 단계에 도달하는 방법의 수 계산
    for (let i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
 
    return dp[n];
}
