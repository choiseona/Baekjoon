function solution(book_time) {
    // 퇴실 시간 기준 10분 후 다시 사용 가능
    // book_time: 예약 시간
    // 코니에게 필요한 최소 객실 수 반환
    
    const answer = [];
    
    //hour:minute 를 minute단위로 변환
    const getMinute = (target) => {
        const [hour, minute] = target.split(":");
        return parseInt(hour)*60 + parseInt(minute);
    }
    book_time = book_time.map(([startTime, endTime]) => [getMinute(startTime), getMinute(endTime) + 10]);
    book_time = book_time.sort((a,b) => a[0] - b[0] || a[1] - b[1]);
    
    // 방 배정
    book_time.forEach(([startTime,endTime]) => {
        const canUseRoomIndex = answer.findIndex((endTimeInUse) => endTimeInUse <= startTime);
        
        // 지금 있는 room들 중 하나에 들어갈 수 있는 경우
        if(canUseRoomIndex > -1) answer[canUseRoomIndex] = endTime;
        
        // 지금 있는 room들에는 들어갈 수 없는 경우
        else answer.push(endTime);
    })

    return answer.length;
}