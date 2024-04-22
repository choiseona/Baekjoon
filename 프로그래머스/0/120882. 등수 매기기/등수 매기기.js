function solution(score) {
    const sortedScore = [...score].sort((a,b) => (b[0]+b[1])/2 - (a[0]+a[1])/2)
    const scoreMap = new Map();
    
    scoreMap.set(sortedScore[0],1);
    for(let i=1; i<sortedScore.length; i++) {
        const targetAverage = (sortedScore[i-1][0] + sortedScore[i-1][1]) / 2;
        const average = (sortedScore[i][0] + sortedScore[i][1]) / 2;
        
        if(targetAverage === average) {
            scoreMap.set(sortedScore[i],scoreMap.get(sortedScore[i-1]));
        } else {
            scoreMap.set( sortedScore[i], i+1);
        }
    }
    
    return score.map((item) => scoreMap.get(item));
}