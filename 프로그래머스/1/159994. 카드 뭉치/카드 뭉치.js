function solution(cards1, cards2, goal) {
    // 카드 모두 사용, 재사용 불가, 순서대로 사용
    for(let i=0; i<goal.length; i++) {   
        if(cards1[0] === goal[i]) cards1.shift();
        else if(cards2[0] === goal[i]) cards2.shift();
        else return 'No'
    }
    
    return "Yes"
}