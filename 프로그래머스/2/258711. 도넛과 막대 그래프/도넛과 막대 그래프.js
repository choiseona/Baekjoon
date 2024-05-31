function solution(edges) {
    const graph = [];
    
    // 그래프 생성
    edges.forEach(([from, to]) => {
        if(!graph[from]) {
            graph[from] = {
                from: [],
                to: [to],
                val: from
            }
        } else graph[from].to.push(to);
        
        if(!graph[to]) {
            graph[to] = {
                from: [from],
                to: [],
                val: to
            }
        } else graph[to].from.push(from);
    })
    

    const answer = [0,0,0,0];
    for(const node of graph) {
        if(!node) continue;
        // 생성한 정점: from.length = 0 && to.length >= 2
        if(node.from.length === 0 && node.to.length >=2) answer[0] = node.val;
        
        // to.length = 0 이면 막대 그래프
        else if(node.to.length === 0) answer[2]++;
        
        // to.length = 2이고 from.length >=2이면 8자 모양 그래프
        else if(node.to.length === 2 && node.from.length >=2 ) answer[3]++
    }
    
    // 도넛 그래프: 시작 정점 to.length - 막대 그래프 개수 - 8자 그래프 개수
    answer[1] = graph[answer[0]].to.length - answer[2] - answer[3]; 
    
    return answer;

}