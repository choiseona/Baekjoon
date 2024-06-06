function solution(maps) {
    // 레버 당겨야 출구문 열 수 있음
    // maps: 미로
    // 탈출 최소 시간 반환
    
    let answer = 0;
    
    // 시작점, 레머위치, 출구위치 구하기
    let start = [], lever = [], exit = [];
    maps.forEach((row,rowIndex) => {
        [...row].forEach((space, columnIndex ) => {
            if(space === "S") start = [rowIndex, columnIndex];
            else if(space === "L") lever = [rowIndex, columnIndex];
            else if(space === "E") exit = [rowIndex,columnIndex];
            else return
        })
    })
    
    const [startY, startX] = start, [leverY, leverX] = lever, [exitY, exitX] = exit
    const XDirection = [-1,1,0,0], YDirection = [0,0,-1,1];
    const mapHeight = maps.length, mapWidth = maps[0].length;
    
    // 레버까지 이동하는데 최소시간 구하기
    const getMinTimeToLever = () => {
        let minTimeToLever = Infinity;
        const visited = Array.from({length:mapHeight}, () => Array.from({length:mapWidth}, () => false))
        const queue = [];
    
        queue.push({y:startY, x:startX, time:0});
        while(queue.length) {
            const {y,x,time} = queue.shift();
            if(y === leverY && x === leverX) minTimeToLever = Math.min(minTimeToLever, time);
        
            for(let i=0; i<4; i++) {
                const newY = y + YDirection[i], newX = x + XDirection[i];
                if(newY < 0 || newX < 0 || newY >= mapHeight || newX >= mapWidth) continue;
                if(visited[newY][newX] || maps[newY][newX] === "X") continue;
                queue.push({y:newY, x:newX, time:time+1});
                visited[newY][newX] = true
            }
        }
        return minTimeToLever;
    }
    
    const getMinTimeToExit = () => {
        let minTimeToExit = Infinity;
        const visited = Array.from({length:mapHeight}, () => Array.from({length:mapWidth}, () => false))
        const queue = [];
        
        queue.push({y:leverY, x:leverX, time:0});
        while(queue.length) {
            const {y,x,time} = queue.shift();
            if(y === exitY && x === exitX) minTimeToExit = Math.min(minTimeToExit, time);
        
            for(let i=0; i<4; i++) {
                const newY = y + YDirection[i], newX = x + XDirection[i];
                if(newY < 0 || newX < 0 || newY >= mapHeight || newX >= mapWidth) continue;
                if(visited[newY][newX] || maps[newY][newX] === "X") continue;
                queue.push({y:newY, x:newX, time:time+1});
                visited[newY][newX] = true
            }
        }
        return minTimeToExit;
    }
    
    const minTimeToLever = getMinTimeToLever();
    if(minTimeToLever === Infinity) return -1;
    
    const minTimeToExit = getMinTimeToExit();
    if(minTimeToExit === Infinity) return -1;
    
    answer = minTimeToLever + minTimeToExit;

    return answer;
}