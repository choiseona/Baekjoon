function solution(jobs) {
    const queue = [];
    const jobsCount = jobs.length;
    let currentTime = 0; // 현재 시각
    let totalTime = 0 // 전체 누적 합
    
    jobs.sort((a,b) => a[0] - b[0]);
    
    while(jobs.length > 0 || queue.length > 0) {

        // 현재 시각 보다 요청한 시각이 빠르거나 같은 작업을 큐에 삽입
        while(jobs[0] && jobs[0][0] <= currentTime) {
            const task = jobs.shift();
            queue.push(task);
        }

                // 큐에 없으면 job에서 하나 꺼내서 실행 
        if(queue.length === 0) {
            currentTime++;
        }
        
        // 큐에 하나만 있으면 바로 실행, 여러 개면 짤은 수행 시간 먼저 실행
        else {
            queue.sort((a,b) => a[1] - b[1]);
            const [requestTime, processingTime] = queue.shift();        
            currentTime += processingTime;
            totalTime += currentTime - requestTime;
        }
        
    }
    return Math.floor(totalTime/jobsCount);
}
