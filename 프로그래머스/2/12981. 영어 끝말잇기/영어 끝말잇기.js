function solution(n, words) {
    // 중복 불가, 한 글자 불가
    // 탈락 사람 번호, 자신의 몇 번째 차례에 탈락하는지 반환
    // 탈락자 없으면 [0,0] 반환
    let answer = [0,0];
    
    for(let i=0; i<words.length; i++) {
        if(i === 0 && words[i].length !== 1) continue;
        
        if (words[i].length === 1 || words[i][0] !== words[i-1][words[i-1].length - 1] || words.slice(0,i).includes(words[i]) ) {
            answer = [i % n + 1, Math.floor(i / n) + 1];
            break;
        }
    }
    
    return answer;
}