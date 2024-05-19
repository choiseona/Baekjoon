function solution(n, wires) {
    // 선 하나 끊어서 두 전력망의 송전탑 개수 차이의 최소값 구하기
    const tree = Array.from(Array(n + 1) , () => []);
    let minGap = 101;
    
    const dfs = function(newTree, vertex, visited) {
        visited[vertex] = true;
        let count = 1;

        for (let nextVertex of newTree[vertex]) {
            if (!visited[nextVertex]) {
                count += dfs(newTree, nextVertex, visited);
            }
        }

        return count;
    };
    
    
    // 송전탑 연결하기
    wires.forEach(([vertex1, vertex2]) => {
        tree[vertex1].push(vertex2);
        tree[vertex2].push(vertex1);
    })
    
    // 선 하나 끊었을 때의 송전탑 개수 차이의 최소값 구하기
    for(let [vertex1, vertex2] of wires) {
        // 선 끊기
        const newTree = JSON.parse(JSON.stringify(tree));
        newTree[vertex1] = newTree[vertex1].filter((v) => v !== vertex2);
        newTree[vertex2] = newTree[vertex2].filter((v) => v !== vertex1);
        
        // 네트워크 크기 계산
        const visited = Array(n + 1).fill(false);
        const size1 = dfs(newTree, vertex1, visited)
        const size2 = n - size1;
        
        const gap = Math.abs(size1 - size2);
        minGap = minGap > gap ? gap : minGap;
    }
    
    return minGap;
}