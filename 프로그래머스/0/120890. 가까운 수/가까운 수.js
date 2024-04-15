function solution(array, n) {
    let answer= array[0];

    for(let i=1; i<array.length; i++) {
        if(Math.abs(answer-n) > Math.abs(array[i]-n)){
            answer = array[i] ;
        }
        else if(Math.abs(answer-n) === Math.abs(array[i]-n)) {
            answer = answer > array[i] ? array[i] : answer;

        }
    }
    
    return answer;
}