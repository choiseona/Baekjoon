function solution(name, yearning, photo) {
    // 추억 점수: 인물의 그리움 점수 총합
    // name:그리운 이름들, yearning:그리움 점수들, photo:그리움 이름 배열 => 각 추억점수 반환
    const answer = [];
    const nameScore = {};
    
    name.forEach((person, index) => nameScore[person] = yearning[index]);
    
    photo.forEach((arr) => {
        const score = arr.reduce((cul,cur) => nameScore[cur] ? cul + nameScore[cur] : cul, 0);
        answer.push(score);
    })
    
    return answer;
}