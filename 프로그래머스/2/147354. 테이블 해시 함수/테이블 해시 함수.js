function solution(data, col, row_begin, row_end) {
    // col번째 컬럼의 값을 기준으로 오름차순 정렬
        // 동일하면 첫 번째 컬럼의 값 기준 내림차순 정렬
    const sortedData = sortData(data, col);
    
    // S_i: i번째 행의 튜플에 대해 각 컬럼의 값을 i로 나눈 나머지들의 합
    const S = getS(sortedData);

    // 모든 S_i를 누적해서 bitwise XOR 한 값을 해시 값으로서 반환
    const xorS = getXorS(S, row_begin, row_end);
    return xorS;
    
}

function sortData(data, col) {
    return data.sort((a,b) => a[col-1] - b[col-1] || b[0] - a[0]); 
}

function getS(data) {
    return data.map((item, index) =>item.reduce((cul,cur) => cul + (cur) % (index+1) , 0));
}

function getXorS(data, rowBegin, rowEnd) {
    return data.slice(rowBegin-1, rowEnd).reduce((cul,cur) => cul ^ cur, 0);
}