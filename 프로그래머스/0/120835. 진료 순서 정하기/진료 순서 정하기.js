function solution(emergency) {
    const sortedEmergency = [...emergency].sort((a,b) => b - a);
    
    const map = new Map();
    
    for(let i=0; i<sortedEmergency.length; i++) {
        map.set(sortedEmergency[i],i+1);
    }
 
    const answer = [];
    
    for(let i=0; i<emergency.length; i++){
        answer.push(map.get(emergency[i]));
    }
    
    return answer;
}