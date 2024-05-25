function solution(numbers) {
    const set = new Set();
    
    for(let i=0; i<numbers.length; i++) {
        for(let j=i+1; j<numbers.length; j++) {
            if(set.has(numbers[i]+numbers[j])) continue;
            set.add(numbers[i]+numbers[j]);
        }
    }
    const sortedSet = [...set].sort((a,b) => a-b);
    
    return sortedSet; 
}