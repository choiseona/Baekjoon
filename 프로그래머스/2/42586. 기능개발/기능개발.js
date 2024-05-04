const getRemainDay = (progress, speed) => {
    return  Math.ceil((100 - progress) / speed);
}

function solution(progresses, speeds) {
    var answer = [];
    
    let target = getRemainDay(progresses[0], speeds[0]);
    let count = 1;
    
    for(let i=1; i<progresses.length; i++){
        const thisRemainDay = getRemainDay(progresses[i], speeds[i]);
        
        if(thisRemainDay > target) {
            answer.push(count);
            count = 0;
            target = getRemainDay(progresses[i], speeds[i]);
        }
        
        if(thisRemainDay <= target) {
            count++;
        }
        
        if(i === progresses.length - 1) {
            answer.push(count);
        }
        
    }
    return answer;
}

