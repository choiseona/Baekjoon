function solution(n, m, section) {
    // n: 페인트벽 길이, m: 롤러 길이, section: 페인트해야할 구역 번호
    // 롤러가 벽에서 벗어나면 안됨
    // 페인트칠 최소 횟수 반환
    let answer = 1;
    let start = section[0]
    
    for(let i=1; i<section.length; i++) {
        if(section[i] - start >= m) {
            answer++;
            start = section[i]
        }
    }
    
    return answer
}