function solution(k, score) {
    // 출연 가수 점수가 누적 상위 k번째 이내이면 명예의 전당에 올림
    // 초기 k일까지는 모든 출연 가수 점수가 명예의 전당에 오름
    // k: 명예 점수 개수, score: 가수들 점수 => 매 일의 명예 전당 최하위 점수 구하기
    
    const answer = [];
    let top = [];
    
    for(let i=0; i<score.length; i++) {
        if(i < k) {
            top.push(score[i]);
            top = top.sort((a,b) => a-b);
        }
        
        else if(score[i] > top[0]) {
            top.shift();
            top.push(score[i]);
            top = top.sort((a,b) => a-b);
        } 
        
        answer.push(top[0]);
    }
    return answer;
}