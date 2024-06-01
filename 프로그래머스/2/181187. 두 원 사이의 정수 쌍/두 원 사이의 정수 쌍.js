function solution(r1, r2) {
    // r1, r2: 정수 반지름, r1 < r2
    // 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수 반환
    
    let answer = 0;
    
    // r1^2 <= x^2 + y^2 <= r2^2
    // y^2 >= r1^2 - x^2
    // y^2 <= r2^2 - x^2
    
    // 한 분면의 개수만 구해서 * 4
    for(let x=1; x<=r2; x++) {
        let minY = x > r1 ? 0: Math.ceil(Math.sqrt(r1**2 - x**2)); 
        let maxY = Math.floor(Math.sqrt(r2**2 - x**2));
        answer += maxY - minY + 1
        
    }
    
    return answer * 4;
}