function solution(elements) {
    // 연속 부분 수열 합 개수
    const elementsLength = elements.length;
    const answer = new Set();
    
    // i: 시작점
    for(let i=0; i < elementsLength; i++) {
        // j: 길이
        for(let j=0; j<elementsLength; j++) {
            let sum = 0;
            for(let k=i; k<=i+j; k++) {
                const index = k % elementsLength;
                sum += elements[index];
            }
            answer.add(sum)
        }
    }
    return [...answer].sort((a,b) => a-b).length;
}