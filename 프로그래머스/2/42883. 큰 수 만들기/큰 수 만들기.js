function solution(number, k) {
    const stack = [];
    let removeCount = 0;
    
    for(let i=0; i<number.length; i++) {
        if(stack.length === 0) stack.push(number[i]);
        
        else {
            while(removeCount < k && stack[stack.length - 1] < number[i]) {
                stack.pop();
                removeCount++;
            }
            stack.push(number[i]);
        }
    }
    
    if(removeCount < k) {
        stack.pop();
    }
    
    return stack.join("")
}