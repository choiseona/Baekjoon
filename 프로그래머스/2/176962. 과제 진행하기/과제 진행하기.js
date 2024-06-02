function solution(plans) {
    
    // 시간을 "분" 단위로 바꿔주는 함수
    const getMinute = (clock) => {
        const [hour, minute] = clock.split(":");
        return parseInt(hour) * 60 + parseInt(minute);
    }   
    
    // 과제 시작 시간 기준 오름차순으로 정렬
    const sortPlans = (([, startTime1, ], [, startTime2, ]) => getMinute(startTime1) - getMinute(startTime2))
    const sortedPlans = plans.sort((a,b) => sortPlans(a,b));
    
    const answer = [];
    const stoppedPlans = [];
    
    for(let i=0; i<sortedPlans.length; i++) {
        let [name,startTime, duration] = sortedPlans[i];
        startTime = getMinute(startTime);
        const endTime = startTime + parseInt(duration);
        
        if(i === sortedPlans.length-1) {
            answer.push(name);
            continue;
        }
        
        const nextPlanStartTime = getMinute(sortedPlans[i+1][1]);  
        const remainTime = endTime - nextPlanStartTime;
        
        // 과제 끝낸 시각에 우선순위: 잠시 멈춰둔 과제 < 새로 시작해야 하는 과제
        // 새로운 과제 시작 시간 되면 진행중 과제 멈추고 새로운 과제 시작
        if(endTime > nextPlanStartTime){
            stoppedPlans.push([name, remainTime]);
        }
        else {
            answer.push(name);
            // 진행중이던 과제 끝났을 때 멈춘 과제 있으면 이어서 진행
            // 멈춰둔 과제 여러 개이면 가장 최근 멈춘 과제부터 시작(선입 후출 -> stack)
            let time = nextPlanStartTime - endTime;
                
            while(time > 0 && stoppedPlans.length > 0) {
                let topRemainTime = stoppedPlans[stoppedPlans.length-1][1];
                const newRemainTime = topRemainTime - time;
                if(newRemainTime <= 0 ){
                    time -= topRemainTime;
                    answer.push(stoppedPlans.pop()[0])
                }
                else {             
                    stoppedPlans[stoppedPlans.length-1][1] = newRemainTime;
                    time = 0;
                }
            }
        }
        
    }
    
    while(stoppedPlans.length > 0) {
        answer.push(stoppedPlans.pop()[0]);
    }

    return answer 
}