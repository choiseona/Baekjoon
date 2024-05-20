function solution(n, lost, reserve) {   
    // 체육복을 스스로 가져온 학생
    let originalStudent = n - lost.length;

    // 체육복을 빌릴 수 있는 학생
    const alreadyReserving = [];
    let sortedReserving = reserve.sort((a,b) => a-b);
    let sortedLost = lost.sort((a,b) => a-b);
    
    // 체육복 여벌을 가져왔는데 도난당한 학생을 reserve에서 제외시키고 스스로 가져온 학생에 카운트
    const commonElements = sortedLost.filter(value => sortedReserving.includes(value));
    originalStudent+= commonElements.length;

    sortedLost = sortedLost.filter(value => !commonElements.includes(value));
    sortedReserving = sortedReserving.filter(value => !commonElements.includes(value));    
        
    // 
    for(let i=0; i<sortedLost.length; i++) {
        for(let j=0; j<sortedReserving.length; j++) {
            const difference = Math.abs(sortedLost[i] - sortedReserving[j]);
            const already = alreadyReserving.find((number) => number === sortedReserving[j]);
            if(!(difference === 1 && !already )) continue;
            alreadyReserving.push(sortedReserving[j]);
            break;
        }
    }
    
    return originalStudent + alreadyReserving.length;
}