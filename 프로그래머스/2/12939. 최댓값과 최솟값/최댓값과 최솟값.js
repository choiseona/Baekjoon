function solution(s) {
    const sortedS = s.split(" ").sort((a,b)=>a-b);
    return `${sortedS[0]} ${sortedS[sortedS.length-1]}`
}