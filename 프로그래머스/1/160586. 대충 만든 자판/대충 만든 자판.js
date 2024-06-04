function solution(keymap, targets) {
    // keymap: 1번 키부터 할당된 문자들, targets: 입력하려는 문자열
    // 문자열을 작성하기 위한 키 최소 누름 횟수 반환  
    // 불가능하면 -1 반환
    
    const map = {};
    
    for(let alphabets of keymap) {
        [...alphabets].forEach((alphabet, index) => {
            map[alphabet] = Math.min(map[alphabet] || Infinity, index + 1)
        })
    }

    let answer = [];
    for(let alphabets of targets) {
        answer.push([...alphabets].reduce((cul,cur) => cul + map[cur],0) || -1)
    }
    
    return answer;
}