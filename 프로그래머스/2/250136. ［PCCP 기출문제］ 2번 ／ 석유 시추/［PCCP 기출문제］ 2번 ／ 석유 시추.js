function solution(land) {
    const height = land.length;
    const width = land[0].length;
    
    const dir_x = [0, 0, -1, 1];
    const dir_y = [-1, 1, 0, 0];
    
    const map = new Map();

    // 너비 우선 탐색
    // 시간 줄이기 위해 각 석유 덩어리에 해당하는 column 반환하기
    const BFS = ([i, j], visited) => {
        const queue = [];
        let count = 0;
        const columnSet = new Set();
        
        queue.push([i, j]);
        columnSet.add(j);
        visited[i][j] = true; 
        count++;
        
        while (queue.length !== 0) {
            const [x, y] = queue.shift();
            for (let k = 0; k < 4; k++) {
                const newX = x + dir_x[k];
                const newY = y + dir_y[k];
                
                if (newX < 0 || newY < 0 || newX >= height || newY >= width) continue;
                if (visited[newX][newY] || !land[newX][newY]) continue;
                
                columnSet.add(newY);
                visited[newX][newY] = true;
                queue.push([newX, newY]);
                count++;
            }
        }
        return [count, columnSet];
    }
    
    // 시간 줄이기 위해 visit이 초기화되는 일 없도록하기
    // visit 하나만 두되, 각 석유 덩어리에 해당하는 column에 대해 map으로 석유 count(key: column, value:count)
    let maxCount = 0;
    const visited = Array.from({ length: height }, () => Array(width).fill(false));
    
    for (let j = 0; j < width; j++) {
        for (let i = 0; i < height; i++) {
            if (land[i][j] && !visited[i][j]) {
                const [queueCount, columnSet] = BFS([i,j], visited);
                columnSet.forEach((column) => {
                    map.set(column, (map.get(column) || 0) + queueCount)
                })
            }
        }
    }
    
    maxCount = Math.max(...map.values())
    return maxCount;
}
