function solution(s) {
    const bracket = {'[': ']', '(': ')', '{':'}'};
    const rotateS = () => {
        s = s.slice(1) + s[0];
    }
    
    const isValidate = () => {
        const stack = [];
        
        for (let key of s) {
            if (key in bracket) stack.push(bracket[key]);
            else if (stack.pop() !== key) return false;
        }
        
        return stack.length === 0;
    }
    
    let answer = 0;
    
    for(let i=0; i<s.length; i++) {
        answer = isValidate(s) ? answer+1 : answer+0;
        rotateS();        
    }
    
    return answer;
}