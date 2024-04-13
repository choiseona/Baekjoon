function solution(age) {
    console.log("c" + 3)
    return [...String(age)].map((number) => String.fromCharCode( 'a'.charCodeAt() + Number(number))).join("");
}