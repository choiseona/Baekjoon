function solution(keyinput, board) {
    let [x,y] = [0,0];
    for(let i=0; i<keyinput.length; i++){
        if(keyinput[i] === "left") {
           x = x-1 <= Math.floor(-board[0]/2) ? x : x-1; 
        } else if(keyinput[i] === "right") {
           x = x+1 > Math.floor(board[0]/2) ? x : x+1;
        } else if(keyinput[i] === "down") {
           y = y-1 <= Math.floor(-board[1]/2) ? y : y-1; 
        } else if(keyinput[i] === "up") {
           y = y+1 > Math.floor(board[1]/2) ? y : y+1;
        } 
    }
    return [x,y];
}