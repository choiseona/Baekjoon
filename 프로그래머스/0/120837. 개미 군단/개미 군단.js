function solution(hp) {

    const 장군개미Count = Math.floor(hp / 5);
    const 장군개미TotalHp = 5 * 장군개미Count;
    
    const 병정개미Count = Math.floor((hp - 장군개미TotalHp) / 3);
    const 병정개미TotalHp = 병정개미Count * 3;
    
    const 일개미Count = Math.floor((hp - 장군개미TotalHp - 병정개미TotalHp) / 1);
    const 일개미TotalHp = 일개미Count * 1;
    
    return 장군개미Count + 병정개미Count + 일개미Count;
}