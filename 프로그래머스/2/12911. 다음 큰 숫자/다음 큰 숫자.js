function solution(n) {
    let answer;
    const n1Count = [...n.toString(2)].filter((el) => el === "1").length;

    for(let i=1;; i++) {
        const nextBiggerNumber1Count = [...(n+i).toString(2)].filter((el) => el === "1").length;
        if(nextBiggerNumber1Count === n1Count) {
            answer = n + i;
            break;
        }
    }
    
    return answer;
}