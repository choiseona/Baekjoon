function solution(name) {
    let spellCount = 0;
    let cursorCount = name.length-1;    
    
    [...name].forEach((alphabet) => {
        spellCount += Math.min((alphabet.charCodeAt() - 'A'.charCodeAt()), 'Z'.charCodeAt() - alphabet.charCodeAt() + 1)
    });
        
    [...name].forEach((_, index) => {
        let nextIndex = index+1;
        
        while(nextIndex < name.length && name[nextIndex] === 'A') {
            nextIndex++;
        }
        
        cursorCount = Math.min(cursorCount, 2 * index + name.length - nextIndex, index + 2 * (name.length - nextIndex));
    })
        
    return spellCount + cursorCount
    
}