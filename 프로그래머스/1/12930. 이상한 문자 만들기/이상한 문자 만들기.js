function solution(s) {
    let answer = '';
    const targetS = s.split(" ");
    
    for(let i=0; i<targetS.length; i++) {
        for(let j=0; j<targetS[i].length; j++) {
            answer += j % 2 === 0 ? targetS[i][j].toUpperCase() : targetS[i][j].toLowerCase();
        }
        if(i !== targetS.length-1)  answer+=" ";
    }
    
    return answer;
}