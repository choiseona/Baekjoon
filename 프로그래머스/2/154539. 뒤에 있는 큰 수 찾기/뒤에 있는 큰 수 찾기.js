function solution(numbers) {
    const stack = [], answer = Array.from({length:numbers.length}, () => -1);
    
    stack.push(0);
    
    for(let i=1; i<numbers.length; i++) {
        // 앞에 작은 숫자가 있을 때 까지만 stack.pop 하고 answer 갱신 
        while(stack.length > 0 && numbers[stack[stack.length-1]] < numbers[i]) {
            answer[stack.pop()] = numbers[i];
        }
        // 현재 숫자 정보 stack에 push
        stack.push(i);
    }      
    
    return answer;
}
