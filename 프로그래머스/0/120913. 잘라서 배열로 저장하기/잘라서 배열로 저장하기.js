function solution(my_str, n) {
    let answer = [];
    
    for(let i=0; i<=my_str.length; i+=n){
        answer.push(my_str.slice(i,i+n))
    }
    
    if(my_str.length % n === 0) answer.pop();
    return answer;
}