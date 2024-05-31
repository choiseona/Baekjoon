function solution(edges) {
    // 각 노드 별 from 개수와 to 개수의 map 생성
    const map = new Map();
    edges.forEach(([from,to]) => {
        const fromCount = map.get(from) || {from: 0, to: 0};
        map.set(from, {from: fromCount.from, to: fromCount.to + 1});
        
        const toCount = map.get(to) || {from: 0, to: 0};
        map.set(to, {from: toCount.from + 1, to: toCount.to});        
    })
    
    // 생성한 정점, 그래프 별 개수 구하기
    const answer = [0,0,0,0];
    for(const node of map) {
        const nodeNumber = node[0];
        const edgeCount = node[1];
        
        // 생성한 정점: from.length = 0 && to.length >= 2
        if(edgeCount.from === 0 && edgeCount.to >= 2) answer[0] = nodeNumber;
        
        // to.length = 0 이면 막대 그래프
        else if(edgeCount.to === 0) answer[2]++;
        
        // to.length = 2이고 from.length >=2이면 8자 모양 그래프
        else if(edgeCount.to === 2 && edgeCount.from >= 2) answer[3]++;
    }
    
    // 도넛 그래프: 시작 정점 to.length - 막대 그래프 개수 - 8자 그래프 개수
    answer[1] = map.get(answer[0]).to - answer[2] - answer[3];

    return answer;

}