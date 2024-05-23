function solution(people, limit) {
    people = people.sort((a,b) => a-b);
    let answer = 0; 
    
    while(people.length !== 0) {
        const lightPerson = people[0];
        const heavyPerson = people[people.length - 1];
        
        // 두명 합이 제한 넘지 않을 때
        if(lightPerson + heavyPerson <= limit) {
            people.shift();
            people.pop();
        }
        
        // 두명 합이 제한 넘을 때 -> 무거운 사람 보내기
        else {
            people.pop();
        }
        
        answer++;
    }
    
    return answer;
}