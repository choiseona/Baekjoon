function solution(cipher, code) {
   return [...cipher].filter((word,index) => (index + 1) % code === 0 ? word : "").join("");
}