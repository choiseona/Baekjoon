function solution(sides) {
    const smallNum = Math.min(sides[0],sides[1]);
    const bigNum = Math.max(sides[0],sides[1]);
    
    return (bigNum-(bigNum-smallNum)) + (smallNum+bigNum-1-bigNum) 
    
}
