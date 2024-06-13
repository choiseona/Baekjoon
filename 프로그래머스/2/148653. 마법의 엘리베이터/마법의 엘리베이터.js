function solution(storey) {
    // -1 +1 -10 +10 -100 +100 ...
    // 음수 층으로 이동하려고 하면 엘리베이터 안움직임
    // storey: 민수와 마법의 엘리베이터가 있는 층
    // 0층으로 가기 위해 필요한 마법의 돌의 최소값 반환
    
    let answer = 0;
    while(storey > 0) {
        const lastNumber = storey % 10;
        if(lastNumber > 5) {
            answer += 10 - lastNumber
            storey += 10 - lastNumber;
        } else if (lastNumber < 5) {
            answer += lastNumber;
            storey -= lastNumber;
        } else {
            const nextNumber = ((storey - lastNumber) / 10) % 10;
            if(nextNumber >= 5) {
                answer += 10 - lastNumber;
                storey += 10 - lastNumber;
            } else {
                answer += lastNumber;
                storey -= lastNumber;
            }
        }
        storey /= 10;
    }
    return answer;
}

// 다른 사람 풀이.. 이런 생각은 어떻게 하는걸까
/*
function solution(storey) {
    if (storey < 5) return storey;
    const r = storey % 10;
    const m = (storey - r) / 10;
    return Math.min(r + solution(m), 10 - r + solution(m + 1));
}
*/