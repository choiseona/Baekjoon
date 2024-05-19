function solution(k, dungeons) {
    const visited = new Array(dungeons.length)
    let maxCount = 0;
    
    // k: 남은 피로도
    const dfs = function(k, visited, count) {
        maxCount = maxCount < count ? count : maxCount; 
        for(let i=0; i<dungeons.length; i++) {
            if(visited[i] || k < dungeons[i][0]) continue;
            visited[i] = 1;
            dfs(k - dungeons[i][1], visited, count + 1);
            visited[i] = 0;
        }
    }
    
    dfs(k,visited,0)
    return maxCount;
}