function solution(storey) {
    // -1 +1 -10 +10 -100 +100 ...
    // 음수 층으로 이동하려고 하면 엘리베이터 안움직임
    // storey: 민수와 마법의 엘리베이터가 있는 층
    // 0층으로 가기 위해 필요한 마법의 돌의 최소값 반환
    
    // 2554 2550(4) 2500(5) 2000(5) 0(2)
    // 2556
    
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