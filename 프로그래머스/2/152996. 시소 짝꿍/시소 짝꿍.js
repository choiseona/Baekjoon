function solution(weights) {  
    // 각 숫자 개수 구하기
    const countMap = {}
    for(const weight of weights) {
        countMap[weight] = countMap[weight] === undefined ? countMap[weight] = 1 : countMap[weight]+1;
    }
    
    let answer = 0;
    const set = Object.keys(countMap);
    
    for(const weight in countMap) {
        // 같은 숫자일 때 nC2
        if(countMap[weight] >= 2) answer += countMap[weight] * (countMap[weight]-1) / 2;
        
        // 다른 숫자일 때
        if(set.includes('' + weight * 2/3)) answer += countMap[weight] * countMap[weight * 2/3];
        if(set.includes('' + weight * 3/4)) answer += countMap[weight] * countMap[weight * 3/4];
        if(set.includes('' + weight * 2/4)) answer += countMap[weight] * countMap[weight * 2/4];
    }
    
    return answer;
}