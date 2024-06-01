function solution(targets) {
    // 미사일을 최소로 사용해 모든 폭격 미사일을 요격
    // 폭격은 개구간(s,e)에 유효함
    // 폭격을 막기 위해 특정 x 좌표에서 y축에 수평이 되도록 미사일 발사
    // 요격 미사일은 실수인 x 좌표에서도 발사 가능
    // targets: 폭격 미사일의 x 좌표 범위 목록
    // 모든 폭격 미사일을 요격하기 위해 필요한 요격 미사일 수의 최소값 반환
    
    let answer = 0;
    let end = 0;
    
    // endX기준 오름차순 정렬
    targets = targets.sort((a,b) => a[1] - b[1]);
        
    // 겹치는 부분 있으면 겹치는 부분으로 개구간 새로 설정
    // 겹치는 부분 없으면 count+1
    for(const [startX, endX] of targets) {
        if(startX >= end) {
            answer++;
            end = endX
        }
    }
    
    return answer;
}