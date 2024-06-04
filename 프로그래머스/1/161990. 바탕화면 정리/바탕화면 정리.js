function solution(wallpaper) {
    // 파일 전부 삭제하려고함
    // wallpaper: 컴퓨터 바탕화면의 상태
        // "." : 빈 칸, "#": 파일이 있는 칸
    
    let top = Infinity, bottom = -Infinity, left = Infinity, right = -Infinity;
    
    wallpaper.forEach((row, rowIndex) => {
        [...row].forEach((word, columnIndex) => {
            if(word !== "#") return;
            top = Math.min(top, rowIndex);
            bottom = Math.max(bottom, rowIndex+1);
            left = Math.min(left, columnIndex);
            right = Math.max(right, columnIndex+1)
        })
    })
    
    return [top,left,bottom,right]
}