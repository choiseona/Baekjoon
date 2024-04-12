function solution(sides) {
    const sortedSides = [...sides].sort((a,b) => a-b);
    const longestLength = sortedSides[sortedSides.length-1];
    return longestLength < sortedSides.reduce((pre,cur) => pre + cur, -1*longestLength) ? 1 : 2 ;
}