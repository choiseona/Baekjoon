function solution(board) {
    // 한 번의 이동: 장애물이나 맨끝에 부딪힐 때까지 이동하는 것, 상하좌우 택1
    // .:빈 공간, R:로봇의 처음위치, D:장애물, G:목표지점
    // 맨 끝이 G가 아니면 G 지나치기
    

    // 로봇의 처음 위치 구하기
    let robotY, robotX = -1;
    
    board.forEach((row, YIndex) => {
        const RXIndex = [...row].findIndex((word) => word === 'R');
        if(RXIndex > -1) {
            [robotY, robotX] = [YIndex,RXIndex];
            return;
        }
    })
    
    // 시작 위치에서 목표 위치까지의 최소 이동 횟수 구하기
    const BFS = (startY, startX) => {
        const visited = Array.from({length:board.length}, () => Array(board[0].length).fill(false))
        const queue = [];
        
        queue.push({robotY:startY, robotX:startX, count:0});
        
        while(queue.length) {
            const {robotY,robotX, count} = queue.shift();
            if(board[robotY][robotX] === 'G') return count;
            visited[robotY][robotX] = true;

            // 상
            let newRobotY = robotY;
            while(newRobotY) {
                if(board[newRobotY-1][robotX] === "D") break;
                newRobotY--;
            }
            if(!visited[newRobotY][robotX]) queue.push({robotY:newRobotY, robotX:robotX, count: count+1});
            
            // 하
            newRobotY = robotY;
            while(newRobotY < board.length-1) {
                if(board[newRobotY+1][robotX]==="D") break;
                newRobotY++;
            }
            if(!visited[newRobotY][robotX]) queue.push({robotY:newRobotY, robotX:robotX, count: count+1});

            // 좌
            let newRobotX = robotX;
            while(newRobotX) {
                if(board[robotY][newRobotX-1] === "D") break;
                newRobotX--;
            }
            if(!visited[robotY][newRobotX]) queue.push({robotY:robotY, robotX:newRobotX, count: count+1});
    
            // 우
            newRobotX = robotX;
            while(newRobotX < board[0].length -1) {
                if(board[robotY][newRobotX+1] === "D") break;
                newRobotX++;
            }
            if(!visited[robotY][newRobotX]) queue.push({robotY:robotY, robotX:newRobotX, count: count+1});
        }
        
        return -1;
        
    }
    
    return BFS(robotY, robotX);
}
