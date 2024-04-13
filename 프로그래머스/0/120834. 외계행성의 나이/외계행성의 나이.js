function solution(age) {
    return [...String(age)].map((number) => String.fromCharCode( 'a'.charCodeAt() + number.charCodeAt() - "1".charCodeAt()+1)).join("");
 
}