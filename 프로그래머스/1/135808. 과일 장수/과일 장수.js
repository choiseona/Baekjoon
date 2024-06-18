function solution(k, m, score) {
    // 사과 상자 가격: p(가장 낮은 점수) * m(개)
    // 얻을 수 있는 최대 이익 반환
    let answer = 0;
    score = score.sort((a,b) => b-a);
    for(let i=0; i<score.length; i+=m) {
        const boxApple = score.slice(i, i+m);
        if(boxApple.length === m) {
            answer += boxApple[boxApple.length-1] * m;
        }
    }
    return answer;
}