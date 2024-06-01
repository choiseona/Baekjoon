function solution(players, callings) {
    // 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부름
    // players: 등수 순서의 선수 이름, callings: 해설진이 부른 이름
    // 경기 후, 선수들의 이름을 등수 순서대로 배열에 담아 반환
    const nameToGradeMap = new Map();
    const gradeToNameMap = new Map();

    players.forEach((name,index) => {
        nameToGradeMap.set(name,index+1);
        gradeToNameMap.set(index+1,name);
    })
        
    callings.forEach((name) => {
        const reversePersonIndex = nameToGradeMap.get(name);
        const reversePerson = gradeToNameMap.get(reversePersonIndex);
        const reversedPersonIndex = reversePersonIndex-1;
        const reversedPerson = gradeToNameMap.get(reversedPersonIndex); 
        
        nameToGradeMap.set(reversePerson, reversedPersonIndex);
        nameToGradeMap.set(reversedPerson, reversePersonIndex);
        gradeToNameMap.set(reversePersonIndex, reversedPerson);
        gradeToNameMap.set(reversedPersonIndex, reversePerson);
        
    })
    
    return ([...nameToGradeMap].sort((a,b) => a[1] - b[1]).map(([name, grade]) => name));
}