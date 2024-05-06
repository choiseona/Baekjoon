function solution(array, commands) {
    const answer = [];
    for(let iter=0; iter<commands.length; iter++) {
        const [i, j ,k] = commands[iter];
        const number = array.slice(i-1 ,j).sort((a,b) => a-b)[k-1];
        answer.push(number)
    }
    return answer;
}