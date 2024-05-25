function solution(n, arr1, arr2) {
    // 지도 겹치기
    // 벽:0, 공백:1
    const answer = [];
    
    const binarySum = (binary1, binary2) => {
        let answer = '';
        for(let i=0; i<binary1.length; i++) {
            if(binary1[i] === '1' || binary2[i] === '1') answer += "#";
            else answer += " ";
        }
        return answer;
    }
    
    for(let i=0; i<n; i++) {
        const binary1 = arr1[i].toString(2).padStart(n, '0');
        const binary2 = arr2[i].toString(2).padStart(n, '0');
        const map = binarySum(binary1, binary2)
        
        answer.push(map);
    }
    
    return answer;    
    
}