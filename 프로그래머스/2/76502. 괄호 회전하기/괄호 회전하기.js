function solution(s) {
    const bracket = {'[': ']', '(': ')', '{':'}'};
    const rotateS = () => {
        s = s.slice(1) + s[0];
    }
    
    const isValidate = () => {
        const stack = [];
        
        for (let char of s) {
            if (char in bracket) stack.push(bracket[char]);
            else if (stack.pop() !== char) return false;
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