function solution(answers) {
    let answer=[];
    const failerChoices = [[1,2,3,4,5],[2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]];
    
    failerChoices.forEach((failerChoice, studentIndex) => {
        let score = 0;
        answers.forEach((answer,i) => {
            const index = i % failerChoice.length;
            if(failerChoice[index] === answer) score++;
        })
        
        // 이전 수포자 점수보다 낮으면 push x,
        // 이전 수포자 점수와 같으면 push,
        // 이전 수포자 점수보다 크면 배열 비우고 push
        // => 결론적으로 가장 큰 점수를 가진 학생만 저장
        const maxScore = answer[0]?.[0];
    
        if(answer.length === 0) answer.push([score, studentIndex + 1]);
        else if(maxScore === score) answer.push([score, studentIndex + 1]);
        else if(maxScore < score) answer = [[score, studentIndex + 1]];
        
    })
    
    return answer.reduce((cul,cur) => [...cul,cur[1]], [])
}