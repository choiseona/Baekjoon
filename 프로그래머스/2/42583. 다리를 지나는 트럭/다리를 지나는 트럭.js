function solution(bridge_length, weight, truck_weights) {
    let count = 0;
    let passTruck = [];
    
    while(truck_weights.length > 0 || passTruck.length > 0) {
        count++; 
        
        // 다리 위의 트럭 위치 1씩 증가
        passTruck = passTruck.map(([truck, location]) => [truck, ++location])
        
        // 맨 앞 트럭 다리 지났을 경우
        if(passTruck[0]?.[1] > bridge_length){
            passTruck.shift();
        }
                
        // 다리에 트럭 하나 추가할 수 있는 경우
        // 다리를 건너는 트럭의 합이 weight가 넘어가지 않도록
        // 다리를 건너는 트럭의 개수가 bridge_length를 넘어가지 않도록
        const totalTruckWeight = passTruck.reduce((cul,[truck,location]) => cul+truck, 0);
        if(truck_weights.length > 0 && totalTruckWeight + truck_weights[0] <= weight) {
            const truck = truck_weights.shift();
            passTruck.push([truck, 1]);
        } 

    }
    
    return count;
    
}