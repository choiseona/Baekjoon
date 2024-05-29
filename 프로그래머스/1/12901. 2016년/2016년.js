function solution(a, b) {
    // 1월 1일: 금요일
    // a월 b일 요일 구하기
    const month = {1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31};
    const day = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU'];
    let count = 0;
    
    for(let i=1; i<a; i++) {
        count += month[i];
    }
    count += b;

    return day[(count-1) % day.length];
    
}