function solution(bandage, health, attacks) {
    const [skillSuccessTime, recoveryPerSecond, additionalRecovery] = bandage;
    let skillTime = 0;
    let hp = health;
    const attacksEndTime = attacks[attacks.length-1][0];
    
    for(let time=1; time<=attacksEndTime; time++) {
        // 몬스터 공격 받으면 피해량만큼 체력 줄어듬
        // 붕대 감기 리셋, 체력 회복x
        // 공격 끝나고 즉시 붕대 감기 시작
        // 체력 0이하 되면 체력 회복 불가
        const [attackTime, hurt] = attacks[0];
        if(time === attackTime) {
            skillTime = 0;
            hp -= hurt;
            attacks.shift();
            if(hp <= 0) return -1;
            continue;
        }
        
        // 체력 회복
        // 현재 체력이 최대 체력보다 커지는 것은 불가능
        // t초 동안 붕대를 감음, 1초마다 x 만큼 체력 회복, t초 연속으로 붕대감으면 y만큼의 체력 추가 회복하고 연속 성공 초기화
        skillTime++;
        hp += recoveryPerSecond;
        if(skillTime >= skillSuccessTime) {
            hp += additionalRecovery;
            skillTime = 0;
        }
        if(hp > health) hp = health;
    }
    
    return hp;
}