function solution(array) {
    let maxNum = 0;
    let maxIndex = 0;
    for(let i=0; i<array.length; i++){
        if(array[i] > maxNum){
            maxNum = array[i];
            maxIndex = i;
        } 
    }
    return [maxNum, maxIndex];
}