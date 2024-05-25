function solution(a, b, n) {
    // a개를 가져다주면 b병 줌, n개를 가져다주면 몇병 받나?
    let answer = 0;
    
    while(n >= a) {
        const newBottles = Math.floor(n/a) * b;
        answer += newBottles;
        n = newBottles + n%a;
    }
    
    return answer;
}