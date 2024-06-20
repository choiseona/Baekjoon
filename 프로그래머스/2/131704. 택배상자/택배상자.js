function solution(order) {
    let count = 0;
    const stack = [];
    
    for(let i=1; i<=order.length; i++) {
        stack.push(i);
        
        while(stack.length && stack.at(-1) === order[count]) {
            count++;
            stack.pop();
        }
    }
    return count;
}