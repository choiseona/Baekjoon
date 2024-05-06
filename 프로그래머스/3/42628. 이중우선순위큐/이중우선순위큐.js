function solution(operations) {
    const queue = [];
    
    while(operations.length !== 0) {
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
        queue.sort((a,b) => a - b); // 오름차순
    }
    
    if(queue.length === 0) return [0,0];
    else return [queue[queue.length-1], queue[0]];

}