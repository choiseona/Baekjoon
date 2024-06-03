function solution(m, n, startX, startY, balls) {
    // 리스트에 담긴 각 위치에 순서대로 공을 놓아가면 "원쿠션" 연습
    // 항상 같은 위치에 공을 놓고 쳐서 리스트에 담긴 위치에 놓인 공을 맞춤
    // 친 공이 각각의 목표로한 공에 맞을 때까지 최소 얼마의 거리를 굴러가야하나?
    
    // m: 당구대의 가로길이, n:세로길이, startX: 공위치, startY: 공위치, balls: 목표 공 위치
    // 각 회마다 머쓱이가 친 공이 굴런가 거리의 최소값의 제곱 반환
    
    // 쿠션 후 입사각과 반사각 동일
    // 꼭짓점에 부딪히면 공이 반대방향으로 감
    const result = [];
    
    const getLineLength = ([x1, y1],[x2, y2]) => {
        return Math.abs(x1-x2)**2 + Math.abs(y1-y2) **2;
    }
    
    balls.forEach(([x,y]) => {
        if(startX === x) {
            const leftRightX2 = x < m / 2 ? 0 - x : m + (m-x);
            const topBottomY2 = startY > y ? n + n - y : 0 - y;
            const leftRight = getLineLength([startX, startY], [leftRightX2,y])
            const topBottom = getLineLength([startX, startY], [x, topBottomY2])
            result.push(Math.min(topBottom, leftRight));
        } 
        
        else if(startY === y) {
            const topBottomY2 = y < n / 2 ? 0 - y : n + (n-y);
            const leftRightX2 = startX > x ? m + m - x : 0 - x;
            const topBottom = getLineLength([startX, startY], [x,topBottomY2])
            const leftRight = getLineLength([startX, startY], [leftRightX2,y]);
            result.push(Math.min(topBottom,leftRight));
        } 
        
        else {
            const top = getLineLength([startX, startY], [x, n + (n-y)]);
            const bottom = getLineLength([startX, startY], [x, 0-y]);
            const left = getLineLength([startX, startY], [0-x, y]);
            const right = getLineLength([startX, startY], [m + (m-x), y]);
            result.push(Math.min(top,bottom,left,right))
        }
    })
    return result
}