function solution(participant, completion) {
    const participantMap = new Map();
    
    participant.forEach((e, i) => {
        participantMap.set(e,(participantMap.get(e)||0)+1);
    })
    
    completion.forEach((e,i) => {
        participantMap.set(e, (participantMap.get(e) || 0)-1);
    })
    
    for(let [key, value] of participantMap) {
        if(value > 0) return key;
    }

}