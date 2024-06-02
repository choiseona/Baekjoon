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
    const dir = {"E":[0,1], "W":[0,-1], "N":[-1,0], "S":[1,0]};
    
const isExistHurdle = ([arriveY, arriveX]) => {
    let isHurdle = false;
    const startX = Math.min(dogX, arriveX);
    const startY = Math.min(dogY, arriveY);
    const endX = Math.max(dogX, arriveX);
    const endY = Math.max(dogY, arriveY);
    for (let i = startY; i <= endY; i++) {
        for (let j = startX; j <= endX; j++) {
            if (road[i][j] === "X") {
                isHurdle = true;
                break;
            }
        }
        if (isHurdle) break;
    }
    return isHurdle;
}
    
    routes.forEach((route) => {
        let [direction, count] = route.split(" "); count = parseInt(count);
        const nextDogXLoction = dogX + count * dir[direction][1],  nextDogYLocation = dogY + count * dir[direction][0];
        if(nextDogXLoction < 0 || nextDogXLoction >= roadXLength || nextDogYLocation < 0 || nextDogYLocation >= roadYLength) return;
        if(isExistHurdle([dogY, nextDogXLoction]) || isExistHurdle([nextDogYLocation, dogX] )) return;

        dogX = nextDogXLoction; dogY = nextDogYLocation;
        
    }) 

    return [dogY, dogX]
}