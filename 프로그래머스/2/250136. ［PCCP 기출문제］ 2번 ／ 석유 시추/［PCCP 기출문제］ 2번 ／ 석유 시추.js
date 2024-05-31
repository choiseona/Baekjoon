function solution(land) {
    const height = land.length;
    const width = land[0].length;
    
    const dir_x = [0, 0, -1, 1];
    const dir_y = [-1, 1, 0, 0];
    
    const map = new Map();

    const BFS = ([i, j], visited) => {
        const queue = [];
        let count = 0;
        const columnSet = new Set();
        
        queue.push([i, j]);
        columnSet.add(j);
        visited[i][j] = true; // 방문 여부 체크
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
