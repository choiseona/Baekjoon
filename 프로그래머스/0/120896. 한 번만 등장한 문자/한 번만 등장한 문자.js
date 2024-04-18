function solution(s) {
    const answer = [];
    const array = new Array(26).fill(0);
    for(let i=0; i<s.length;i++){
        array[s[i].charCodeAt() - 'a'.charCodeAt()]++;
    }
    array.map((item,index) => item ===1 && answer.push(String.fromCharCode('a'.charCodeAt() + index)));
    return answer.sort().join("")
 

}