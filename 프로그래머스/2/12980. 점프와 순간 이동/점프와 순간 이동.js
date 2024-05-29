function solution(n) {
    // 한 번에 K 칸 앞으로 점프 또는 현재까지 온거리 * 2 위치로 순간이동
    // K 칸 점프하면 K 만큼의 건전지 사용 -> 순간이동이 효율적
    // 건전지 사용량 최소값 구하기
    
    // 2로 나눠서 1이 될 때 까지의 홀수 개수
    let answer = 0;
    while(n > 0) {
        if(n % 2 !== 0) answer++;
        n  = Math.floor(n/2);
    }
    return answer;
}