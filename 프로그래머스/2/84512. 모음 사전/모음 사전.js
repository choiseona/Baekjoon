function solution(word) {
    const aeiou = "AEIOU";
    let answer = 0;
    let cnt = 0;
    
    const dfs = function(alphabet) {
        if(alphabet.length > 5) return;
        if(alphabet === word) {
            answer = cnt;
            return;
        }
        
        cnt++;
        
        for(let i=0; i<5; i++) {
            dfs(alphabet + aeiou[i]);
        }
    }
    
    dfs("");
    return answer;
}