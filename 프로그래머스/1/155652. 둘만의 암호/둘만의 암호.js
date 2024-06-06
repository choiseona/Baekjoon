function solution(s, skip, index) {
    const aCode = 'a'.charCodeAt();
    
    // 알파벳 배열 만들기
    let alphabet = [];
    for(let i=0; i<26; i++) {
        alphabet.push(String.fromCharCode(aCode + i));     
    }
    
    // 알파벳 배열에서 skip 해당하는 것 제거
    skip.split("").forEach((target) => {
        alphabet = alphabet.filter((element) => target!==element);
    })
   
    // 규칙 적용 후 s 반환
    let answer = '';
    answer = s.split("").map((element) => {
        let alphabetIndex = alphabet.findIndex((target) => target === element);
        alphabetIndex = (alphabetIndex + index) % alphabet.length;
        return alphabet[alphabetIndex];
    })

    return answer.join("");
    
}