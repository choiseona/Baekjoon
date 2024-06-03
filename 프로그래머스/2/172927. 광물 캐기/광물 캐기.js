function solution(picks, minerals) {

    const fatigue = {diamond:{diamond:1, iron:1, stone:1}, iron:{diamond:5, iron:1, stone:1}, stone:{diamond:25, iron:5, stone:1}};
    
    // 곡괭이 수로 광물들을 다 캐지 못할 경우 뒤의 광물 없애는 예외처리
    minerals = minerals.slice(0,picks.reduce((cul,cur) => cul + cur,0)*5);
    
    // 광물 5개 묶음별로 각 곡괭이를 사용했을 때 피로도 저장
    let fatigueByToolList = [];
    
    for(let i=0; i<minerals.length; i+=5) {
        const slicedMinerals = minerals.slice(i,i+5);
        const diamondFatigue = slicedMinerals.reduce((cul,cur) => cul + fatigue["diamond"][cur],0);
        const ironFatigue = slicedMinerals.reduce((cul,cur) => cul + fatigue["iron"][cur],0);
        const stoneFatigue = slicedMinerals.reduce((cul,cur) => cul + fatigue["stone"][cur],0);
        fatigueByToolList.push({startIndex:i, length:slicedMinerals.length, diamond:diamondFatigue, iron:ironFatigue, stone:stoneFatigue});
    }
    
    // stone 기준으로 리스트를 내림차순 정렬하여 answer 구하기
    let [diamondToolCount, ironToolCount, stoneToolCount] = picks
    let answer = 0;
    fatigueByToolList = fatigueByToolList.sort((a,b) => b.stone - a.stone);
    
    for(let i=0; i<fatigueByToolList.length; i++) {
        if(diamondToolCount === 0 && ironToolCount ===0 && stoneToolCount === 0) break;
        if(diamondToolCount) {
            answer += fatigueByToolList[i].diamond;
            diamondToolCount--;
        } else if(ironToolCount) {
            answer += fatigueByToolList[i].iron;
            ironToolCount--;
        } else if(stoneToolCount) {
            answer += fatigueByToolList[i].stone;
            stoneToolCount--;
        }
    }
    
    return answer;
    
}