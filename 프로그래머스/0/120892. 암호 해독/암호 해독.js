function solution(cipher, code) {
   return [...cipher].map((word,index) => index % code === code - 1 ? word : "").join("");
}