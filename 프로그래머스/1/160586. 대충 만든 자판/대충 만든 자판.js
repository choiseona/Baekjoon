function solution(keymap, targets) {
    // keymap: 1번 키부터 할당된 문자들, targets: 입력하려는 문자열
    // 문자열을 작성하기 위한 키 최소 누름 횟수 반환  
    // 불가능하면 -1 반환
    
    const map = [];
    
    keymap.forEach((alphabets) => {
        [...alphabets].forEach((alphabet, index) => {
            map[alphabet] = Math.min(map[alphabet] || Infinity, index+1);
        })
    })
    
    let answer = [];
    targets.forEach((alphabets) => {
        let isFail = false;
        let sum = 0;
        
        for(let key of alphabets) {
            if(!map[key]) {
                isFail = true;
                break;
            } else {
                sum += map[key];
            }
        }
        
        if(isFail) answer.push(-1);
        else answer.push(sum)
    })
    
    return answer;
}