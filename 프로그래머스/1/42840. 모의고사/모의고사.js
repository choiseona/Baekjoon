function solution(answers) {
    let answer=[];
    let scores=[];
    const failerChoices = [[1,2,3,4,5],[2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]];
    
    // 각 점수 계산
    failerChoices.forEach((failerChoice) => {
        const score = answers.filter((answer,index) => {
             return answer === failerChoice[(index % failerChoice.length)]
        }).length;
        scores.push(score);
    })
    
    // 최대값 추출하여 답(인덱스) 구하기
    const max = Math.max(...scores)
    scores.forEach((score,index) => score === max && answer.push(index+1));
    
    return answer;
    
}