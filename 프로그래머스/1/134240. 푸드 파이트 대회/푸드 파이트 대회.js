function solution(food) {
    // 음식 종류, 양, 순서 같도록, 칼로리 낮은 음식부터 먹도록 배치
    // food[0]: 물은 항상 1개, fodd[i]: 음식의 개수
    let answer = '';
    for(let i=1; i<food.length; i++) {
        answer += i.toString().repeat(Math.floor(food[i]/2));
    }
    const reversed = [...answer].reverse().join("");
    
    answer += 0;
    answer += reversed;
    
    return answer;
}