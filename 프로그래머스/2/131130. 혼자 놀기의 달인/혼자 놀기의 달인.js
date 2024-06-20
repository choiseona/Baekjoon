function solution(cards) {
    let visited = Array.from({length:cards.length}, () => false);
    let counts = [];
    
    for(let i=0; i<cards.length; i++) {
        if(visited[i]) continue;
        const count = DFS(cards, visited, i);
        counts.push(count);
    }
    
    counts = counts.sort((a,b) => b-a);
    return counts[0] * (counts[1] || 0);
}

function DFS(cards, visited, startIndex) {
    let iterator = startIndex;
    let count = 0;
    
    do {
        visited[iterator] = true;
        iterator = cards[iterator]-1;
        count++;
    } while(!visited[iterator])
        
    return count;
}