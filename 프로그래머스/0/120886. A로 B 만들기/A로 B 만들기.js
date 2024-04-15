function solution(before, after) {
    sortedBefore = [...before].sort();
    sortedAfter = [...after].sort();
    
    for(let i=0; i<before.length; i++){
        if(sortedBefore[i] !== sortedAfter[i]){
            return 0;
        }
    }
    return 1;
}