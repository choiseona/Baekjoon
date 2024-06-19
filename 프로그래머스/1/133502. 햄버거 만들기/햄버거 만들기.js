
function solution(ingredient) {
    const stack = [];
    let count = 0;
    for (const item of ingredient) {
        stack.push(item);
        if (stack[stack.length-1] !== 1) continue;
        if (stack[stack.length-2] !== 3) continue; 
        if (stack[stack.length-3] !== 2) continue;
        if (stack[stack.length-4] !== 1) continue;
        count++;
        stack.splice(-4);
    }
    
    return count;
}