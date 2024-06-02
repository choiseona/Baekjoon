function solution(park, routes) {
    // 길: 'O', 장애물: 'X', 현재 위치: "S"
    // 공원 벗어나거나 장애물 있으면 해당 명령 무시하고 다음 명령 수행
    
    const road = [];
    let dogX, dogY; 
    
    // 길 상태, 강아지 위치 구하기
    park.forEach((partialRoad, RowIndex) => {
        road.push(partialRoad);
        const dogPosition =[...partialRoad].findIndex((word) => word === 'S');
        if(dogPosition < 0) return;
        dogY = RowIndex; dogX = dogPosition
    });
    
    // 명령 수행
    // 공원 벗어나거나 장애물 있으면 해당 명령 무시하고 다음 명령 수행
    const roadYLength = road.length;
    const roadXLength = road[0].length;
    const isExistHurdle = ([departY, departX], [arriveY, arriveX]) => {
        let isHurdle = false;
        if(arriveY - departY < 0) [arriveY, departY] = [departY, arriveY];
        if(arriveX - departX < 0) [arriveX, departX] = [departX, arriveX];
        for(let i=departY; i<=arriveY; i++) {
            for(let j=departX; j<=arriveX; j++) {
                if(road[i][j] === "X") isHurdle = true;
            }
        }
        return isHurdle;
    }
    
    routes.forEach((route) => {
        let [direction, count] = route.split(" ");
        count = parseInt(count);
        if(direction === "E" && dogX + count < roadXLength && !isExistHurdle([dogY, dogX], [dogY, dogX+count])) dogX+=count;
        else if(direction === "W" && dogX - count >=0 && !isExistHurdle([dogY, dogX], [dogY, dogX-count])) dogX-=count
        else if(direction === "N" && dogY - count >= 0 && !isExistHurdle([dogY, dogX], [dogY - count, dogX])) dogY-=count
        else if(direction === "S" && dogY + count < roadYLength && !isExistHurdle([dogY, dogX], [dogY + count, dogX])) dogY+=count;
        
    }) 

    return [dogY, dogX]
}