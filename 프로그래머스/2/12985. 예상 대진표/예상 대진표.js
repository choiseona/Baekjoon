function solution(n,a,b) {
    // 다음 라운드에서 1번 ~ N/2번 부여받음
    // 게임은 최종 한 명이 남을 때 까지
    // n:게임 참가자 수, a: 참가자 번호, b: 경쟁자 번호
    // a와 b는 몇 번째 라운드에서 만나나
    
    let answer = 0;
    
    while (b - a !== 0) {
        answer++;
        a = Math.ceil(a / 2);
        b = Math.ceil(b / 2);
    }
    
    return answer;
    
    
}