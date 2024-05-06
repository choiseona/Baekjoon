function solution(operations) {
    const queue = [];
    
    while(operations.length !== 0) {
        queue.sort((a,b) => a - b); // 오름차순
        
        const [operation, number] = operations.shift().split(" ");
        if(operation === "I") {
            queue.push(parseInt(number));
        }
        else if(operation === "D" && number === "1" && queue.length > 0) {
            queue.pop();
        }
        else if(operation === "D" && number === "-1" && queue.length > 0) {
            queue.shift();
        }
    }
    
    const min = queue.length === 0 ? 0 : Math.min(...queue);
    const max = queue.length === 0 ? 0 : Math.max(...queue);
    
    return [max,min];
}