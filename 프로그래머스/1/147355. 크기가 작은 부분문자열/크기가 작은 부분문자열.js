function solution(t, p) {
    let answer = 0;
    for(let i=0; i <= t.length - p.length; i++) {
        const slicedT = t.slice(i, i+p.length);
        if(parseInt(slicedT) <= parseInt(p)) answer++;
    }
    return answer;
}