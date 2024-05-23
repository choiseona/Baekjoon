function solution(s) {
    const stack = [];
    
    for(let i=0; i<s.length; i++) {
        const target = s[i];
        
        // stack 비었으면 그냥 push
        if(stack.length === 0) stack.push(target);
        
        // stack 안비었고 같은 문자열이면 stack의 top이 같은 문자열이 아닐때까지 stack.pop
        else if(stack[stack.length -1] === target){
            while(stack[stack.length-1] === target) {
                stack.pop();
            }
        }
        
        // stack 안비었고 같은 문자열이 아니면 push
        else if(stack[stack.length -1] !== target) {
            stack.push(target);
        }
    }
    
    return stack.length === 0 ? 1 : 0;
}