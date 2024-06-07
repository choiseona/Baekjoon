function solution(maps) {
    // 'X':바다, 숫자:무인도(식량)
    // 상하좌우 연결되는 숫자 합은 무인도에서 최대 며칠동안 머물 수 있는지 나타냄
    // maps: 지도
    // 각 섬에서 최대 며칠씩 머물 수 있는지 오름차순으로 반환
        // 지낼 수 있는 무인도 없으면 -1을 배열에 담아 반환
    
    const mapHeight = maps.length, mapWidth = maps[0].length;
    const xDirection = [0,0,-1,1], yDirection = [-1,1,0,0];
    const visited = Array.from({length:mapHeight}, () => Array.from({length:mapWidth}, () => false));
    
    const BFS = ([startY,startX]) => {
        const queue = [];
        let eat = 0;
        
        queue.push({y:startY, x:startX});
        visited[startY][startX] = true;
        
        while(queue.length) {
            const {y,x} = queue.shift();
            eat += parseInt(maps[y][x]);
            
            for(let i=0; i<4; i++) {
                const newY = y+yDirection[i], newX = x+xDirection[i];
                if(newX < 0 || newY < 0 || newY >= mapHeight || newX >= mapWidth) continue;
                if(visited[newY][newX] || maps[newY][newX] === "X") continue;
                
                queue.push({y:newY, x:newX});
                visited[newY][newX] = true;
            }
            
        }
        return eat;
    }
    
    let answer = [];
    for(let i=0; i<mapHeight; i++) {
        for(let j=0; j<mapWidth; j++) {
            if(maps[i][j] === "X" || visited[i][j]) continue;
            const eat = BFS([i,j]);
            answer.push(eat);
        }
    }
    answer = answer.length > 0 ? answer.sort((a,b) => a-b) : [-1];
    return answer;
}