function solution(ingredient) {
    // 1: 빵, 2:야채, 3:고기
    const stack = [];
    const next = {1:2, 2:3 , 3:1};
    let count = 0;
    let current = '';
    
    for(const item of ingredient) {
        if(item === next[current[current.length-1]]) current += item;
        else if(item === 1) current = '1';
        else current = '';
        stack.push(item);
        
        if(current === '1231') {
            count++;
            for(let i=0; i<4; i++) stack.pop();
            if(stack.slice(stack.length-3).join("") === '123') current = '123';
            else if(stack.slice(stack.length-2).join("") === '12') current = '12';
            else if(stack.slice(stack.length-1).join("") === "1") current = '1';
            else current = '';
            
        }
    }
    
    return count;
}