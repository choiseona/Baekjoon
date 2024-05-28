function solution(k, tangerine) {
    // 크기별로 분류했을 때 서로 다른 종류의 수 최소화
    
    // key:귤의 크기, value: 해당 크기의 귤 개수
    const map = new Map();
    tangerine.forEach((number) => map.set(number, map.get(number) + 1 || 1))
    
    // 귤의 크기 기준 내림차순으로 정렬
    const sortedMap = [...map].sort((a,b) => b[1] - a[1]);
    
    // 앞에서부터 귤의 개수(count)가 k보다 작거나 같을때까지 귤의 종류 + 1(answer)
    let count = 0;
    let answer = 0;
    for(let i=0; count < k; i++) {
        answer++;
        count += sortedMap[i][1];
    }
    
    return answer;
}