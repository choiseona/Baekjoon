function solution(board) {
    // 승리 조건 확인 함수
    const checkWin = (symbol) => {
        // 가로 확인
        for(let i = 0; i < 3; i++) {
            if(board[i][0] === symbol && board[i][1] === symbol && board[i][2] === symbol) return true;
        }
        // 세로 확인
        for(let i = 0; i < 3; i++) {
            if(board[0][i] === symbol && board[1][i] === symbol && board[2][i] === symbol) return true;
        }
        // 대각선 확인
        if(board[0][0] === symbol && board[1][1] === symbol && board[2][2] === symbol) return true;
        if(board[0][2] === symbol && board[1][1] === symbol && board[2][0] === symbol) return true;
        
        return false;
    }
    
    // O와 X 개수 계산
    // X가 더 많거나 O와 X 개수 차이가 1보다 크면 실수한 것임
    let OCount = 0, XCount = 0;
    for(const line of board) {
        for(const space of line) {
            if(space === "O") OCount++;
            else if(space === "X") XCount++;
        }
    }
    if(OCount < XCount || OCount - XCount > 1) return 0;


    // O와 X가 모두 승리한 경우가 있는지 확인
    // 둘 다 승리한 경우는 실수한 것임
    const OSuccess = checkWin("O");
    const XSuccess = checkWin("X");
    if(OSuccess === true && XSuccess === true) return 0;
    
    // X가 성공했는데 O를 놓는 경우 실수한 것임
    // 즉, X가 성공했는데 O가 X의 개수보다 하나 많으면 실수한 것임
    if(XSuccess === true && OCount > XCount) return 0;
    if(OSuccess === true && OCount === XCount) return 0;
    return 1;
}
