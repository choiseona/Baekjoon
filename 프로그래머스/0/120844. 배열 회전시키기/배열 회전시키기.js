function solution(numbers, direction) {
    const answer=[...numbers];
    if(direction === "right") {
        const tail = answer.pop();
        answer.unshift(tail);
    }
    
    else if(direction === "left") {
        const head = answer.shift();
        answer.push(head);
    }
    
    return answer;
}