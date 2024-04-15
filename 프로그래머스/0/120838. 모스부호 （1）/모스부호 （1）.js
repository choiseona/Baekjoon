function solution(letter) {
    const morse = [
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    ];
    
    return letter.split(" ").map((plain) => String.fromCharCode('a'.charCodeAt() + morse.indexOf(plain))).join("");
}
